/*
* game.h
* This file contains the game functions and structure
* Author: Nischay Joshi
* Date: 2023/05/29
*/
#ifndef GAME_H
#define GAME_H
#define LED_START_STATE 0x01
#define SpeedFactor 0.1

#include "gpioLinux.h"
#include "imu.h"

typedef struct 
{
    uint8_t ledstate;
    float currentVariable;
    float lastVariable;
    float rawVariable;
    float dt;
    float velocity;
    float distance;
    gpio_t *LED_struct;
} game_t;

/*
* This function is used to initialize the game
* @param game is the game structure
*/
void game_init(game_t *game, gpio_t *leds);

/*
* This function is used to update the game
* @param game is the game structure
*/
void game_update(game_t *game, IMUData *imuData);
#endif
