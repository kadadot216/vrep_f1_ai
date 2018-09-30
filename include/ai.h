/*
** EPITECH PROJECT, 2018
** ai.h
** File description:
** Header file for AI related functions
*/

#ifndef __AI_H__
#define __AI_H__

#include "vehicle.h"

dirside_t	dirside_set(lidar_t *this);
vehicle_t	*direction_set_side(vehicle_t *this);
vehicle_t	*ai_update_direction(vehicle_t *this);
vehicle_t	*ai_update_speed(vehicle_t *this);

#endif /* __AI_H__ */
