/*
** EPITECH PROJECT, 2018
** vehicle.h
** File description:
** Header file for vehicle related functions
*/

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "need4stek.h"

typedef	struct	vehicle_s {
	float	speed;
	float	direction;
	float	lidar[LRES_SIZE];
}	vehicle_t;

vehicle_t	*vehicle_update_speed(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_set_speed(vehicle_t *this, float speed);
vehicle_t	*vehicle_set_direction(vehicle_t *this, float wheels);
vehicle_t	*vehicle_set_lidar(vehicle_t *this, float *lidar);
vehicle_t	*vehicle_reset(vehicle_t *this);
vehicle_t	vehicle_new(void);

#endif /* __VEHICLE_H__ */
