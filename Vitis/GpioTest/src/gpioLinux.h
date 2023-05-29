/*
*   gpio.linux.h
*   This files contains the functions used to control the GPIOs on the Zynq
*   SoC. The functions are implemented in LinuxGpio.c
*   Author: Nischay Joshi
*   Date: 2023/05/29
*/

#ifndef GPIO_LINUX_H
#define GPIO_LINUX_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>

//Structure to store the GPIO information
typedef struct {
    uint32_t gpio_addr;
    int mem_fd;
    volatile uint32_t *gpio;
    uint32_t gpio_mask;
} gpio_t;

/*
*   Function to initialize the GPIO
*   @param gpio_addr: The base address of the GPIO
*   @param gpio_mask: The mask to be used
*   @return: A pointer to the gpio_t structure
*/
gpio_t *gpio_init(uint32_t gpio_addr, uint32_t gpio_mask);

/*
*   Function to set the values of the GPIO
*   @param mygpio: A pointer to the gpio_t structure
*   @param value: The value to be set
*   @param mask: The mask to be used
*/
void gpio_set(gpio_t *mygpio, uint32_t value);
#endif
