/*
*   imu.c
*   This file contains the function definitions for the IMU
*   outlined in the imu.h file
*   Author: Nischay Joshi
*   Date: 2023/05/29
*/

#include "imu.h"


void SetupIMU(IMUData * imu){
    imu->Address = IMU_addr;
    //open the I2C device
    imu->fd = OpenI2CDevice(I2CBUS, IMU_addr);
    
    //test the IMU
    if(!IMUTest(imu)){
        printf("IMU Test Failed\n");
        return;
    }

    //reset the IMU
    imu->DataBuffer[0] = 0x6B;
    imu->DataBuffer[1] = 0x00;
    I2C_Write(imu->fd, imu->DataBuffer, 2);

    //set the accelerometer range to +/-8g
    imu->DataBuffer[0] = 0x1C;
    imu->DataBuffer[1] = 0x10;
    //set the gyroscope range to +/-1000dps
    imu->DataBuffer[2] = 0x1B;
    imu->DataBuffer[3] = 0x10;
    I2C_Write(imu->fd, imu->DataBuffer, 4);
    //Setup done
    printf("IMU Setup complete\n");
}

void GetXYAngles(IMUData *imu){
    //We read the Accelerometer values from the IMU and then Calculate the angles
    imu->DataBuffer[0] = 0x3B;
    I2C_Write(imu->fd, imu->DataBuffer, 1);
    I2C_Read(imu->fd, imu->DataBuffer, 6);
    float IMU_Accel[3] = {0};
    //Read the raw Acceleration values
    for(int i = 0; i < 3; i++){
        IMU_Accel[i] = (int16_t)(imu->DataBuffer[2*i] << 8 | imu->DataBuffer[2*i+1]) * 1 / IMU_Accel_Scale;
    }

    //now compute the angles
    float mu = 0.01;
    float sgn = IMU_Accel[2]>= 0 ? 1 : -1;
    imu->XAngle = atan2(IMU_Accel[1], sgn * sqrt(pow(IMU_Accel[2],2) + mu * pow(IMU_Accel[0],2))) * 180 / PI;
    imu->YAngle = atan2(-1 * IMU_Accel[0], sqrt(pow(IMU_Accel[1], 2) + pow(IMU_Accel[2], 2))) * 180 / PI;
}

int IMUTest(IMUData *imu){
    //Read from the IMU's Who am i register :0x75
    imu->DataBuffer[0] = 0x75;
    I2C_Write(imu->fd, imu->DataBuffer, 1);
    I2C_Read(imu->fd, imu->DataBuffer, 1);
    if(imu->DataBuffer[0] == 0x68){
        printf("IMU Test Passed\n");
        return 1;
    }
    return 0;
}

void IMUCleanup(IMUData *imu){
    //Set the variables to 0
    imu->XAngle = 0;
    imu->YAngle = 0;
    imu->fd = 0;
    imu->Address = 0;
}