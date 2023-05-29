/*
* i2cLinux.h
* Created on: 2023/05/29
* Author: Nischay Joshi
* Description: This file contains the function declarations for I2C communication on Linux
*/

#ifndef I2C_LINUX_H
#define I2C_LINUX_H

#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>

/*
 * Opens a I2C Device using the standard Linux I2c Driver.
 * Params
 * I2C_BusNumber :	I2C Bus Number that You wish to connect the device to
 * I2C_DeviceAddress: The address of the device that you want to connect to.
 *
 * Returns: The file descriptor is the connection was established successfully. Otherwise negative values are returned to signal that something was wrong
 */
int OpenI2CDevice(int I2C_BusNumber, int I2C_DeviceAddress);


/*
 * This functions writes Data to I2C device connected to a specific i2cFileDescriptor
 * Params:
 * i2cfileDescriptor : The file descriptor for the i2c device
 * *Data: The pointer pointing to the buffer storing the data
 * BytestoWrite: Well, the no. of bytes from the buffer to write to.
 */
void I2C_Write(int i2cfileDescriptor, uint8_t *Data, uint8_t BytestoWrite);

/*
 * This functions Reads Data to I2C device connected to a specific i2cFileDescriptor
 * Params:
 * i2cfileDescriptor : The file descriptor for the i2c device
 * *Data: The pointer pointing to the buffer that will store the data
 * BytestoWrite: Well, the no. of bytes from the buffer to read.
 */
void I2C_Read(int i2cfileDescriptor, uint8_t *Data, uint8_t BytestoRead);

#endif
