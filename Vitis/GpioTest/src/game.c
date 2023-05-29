/*
*   game.c
*   This file contains the game logic for the IMU game.
*   Author: Nischay Joshi
*   Date: 2023/05/29
*/

#include "game.h"

void game_init(game_t *game, gpio_t *leds){
    game->ledstate = LED_START_STATE;
    game->currentVariable = 0;
    game->lastVariable = 0;
    game->LED_struct = leds;
    game->dt = IMUSleepus/1000000;
    game->rawVariable = 0;
    game->distance = 0;
    //write the start state to the leds
    gpio_set(game->LED_struct, game->ledstate);
}

void game_update(game_t *game, IMUData *imuData){
    //get the current variable
    game->rawVariable = imuData->XAngle;
    game->currentVariable = imuData->XAngle*SpeedFactor + game->lastVariable*(1-SpeedFactor);
    game->lastVariable = game->currentVariable;

    game->velocity += game->currentVariable*game->dt;
    game->distance += game->velocity*game->dt*game->dt;
    
    printf("Current Variable: %f\n",game->currentVariable);
    printf("Velocity: %f\n",game->velocity);
    printf("Distance : %f\n",game->distance);
}
