/*
*   registerlinux.h
*   This files contains the functions used to control the General Registers on Zynq SoC
*   The functions are implemented in registerLinux.c
*   Author: Nischay Joshi
*   Date: 2023/05/29
*/

#ifndef REGISTER_LINUX_H
#define REGISTER_LINUX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>

//Structure to store the register information
typedef struct {
    uint32_t register_addr;
    int mem_fd;
    volatile uint32_t *register_ptr;
} ZynqRegister_t;

/*
*   Function to initialize the register
*   @param registerBase_addr: The base address of the register
*   @return: A pointer to the register_t structure
*/
ZynqRegister_t *register_init(uint32_t registerBase_addr);

/*
*   Function to set the values of the register
*   @param myregister: A pointer to the register_t structure
*   @param offset: The offset of the register to write to the final addres will be (register_addr + offset)
*   @param value: The value to write to the register
*   @param mask: The mask to apply to the value before writing to the register is format is 0x0000FFFF, where 0s are the bits to be masked(ignored)
*/
void register_set(ZynqRegister_t *myregister, uint32_t offset, uint32_t value, uint32_t mask);

/*
*   Function to read the values of the register
*   @param myregister: A pointer to the register_t structure
*   @param offset: The offset of the register to read from the final addres will be (register_addr + offset)
*   @return: The value read from the register
*/
uint32_t register_read(ZynqRegister_t *myregister, uint32_t offset);
#endif
