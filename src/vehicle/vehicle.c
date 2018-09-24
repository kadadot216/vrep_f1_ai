/*
** EPITECH PROJECT, 2018
** vehicle.c
** File description:
** Vehicle related functions
*/

#include "need4stek.h"
#include "vehicle.h"

vehicle_t	*vehicle_reset(vehicle_t *this)
{
	float	empty_lidar[LRES_SIZE] = { 0.0f };

	this = vehicle_set_speed(this, 0.0f);
	this = vehicle_set_direction(this, 0.0f);
	this = vehicle_set_lidar(this, empty_lidar);
	this = vehicle_set_actions(this);
	this = vehicle_set_getinfos(this);
	return (this);
}

vehicle_t	vehicle_new(void)
{
	vehicle_t	new;

	vehicle_reset(&new);
	return (new);
}
