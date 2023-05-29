/*
*   i2cLinux.c
*   This file contains the functions for the I2C communication
*   outlined in the i2cLinux.h file
*   Author: Nischay Joshi
*   Date: 2023/05/29
*/

#include "i2cLinux.h"

int OpenI2CDevice(int I2C_BusNumber, int I2C_DeviceAddress){
	char filename[20];
	int i2cfileDescriptor = 0;
	sprintf(filename, "/dev/i2c-%d", I2C_BusNumber);
	printf("%s\n", filename);
	//Try to open the device file
	i2cfileDescriptor = open(filename, O_RDWR);
	if(i2cfileDescriptor < 0){
		printf ( "Failed to open %s, open() returned %i\n" , filename , i2cfileDescriptor);
		return(i2cfileDescriptor);
	}
	//try to connect to the i2c device
	if(ioctl(i2cfileDescriptor, I2C_SLAVE, I2C_DeviceAddress) < 0){
		printf ( "Failed to find device 0x%x on i2c bus %i\n" , I2C_DeviceAddress , I2C_DeviceAddress ) ;
		i2cfileDescriptor = -1;
		return(i2cfileDescriptor);
	}
	printf("I2C Setup complete\n");
	return(i2cfileDescriptor);
}

void I2C_Write(int i2cfileDescriptor, uint8_t *Data, uint8_t BytestoWrite){
	int Written = write(i2cfileDescriptor, Data, BytestoWrite);
	if(Written != BytestoWrite) {
		printf("ERROR!!! Bytes written: %d, was expecting to write: %d/n", Written, BytestoWrite);
	}
	//printf("I2c write complete\n");
}

void I2C_Read(int i2cfileDescriptor, uint8_t *Data, uint8_t BytestoRead){
	int Read = read(i2cfileDescriptor, Data, BytestoRead);
	if(Read != BytestoRead) {
		printf("ERROR!!! Bytes Read: %d, was expecting to read: %d/n", Read, BytestoRead);
	}
	//printf("I2c read complete\n");
}