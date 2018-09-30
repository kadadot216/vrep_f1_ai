/*
** EPITECH PROJECT, 2018
** direction.c
** File description:
** Direction related functions for AI
*/

#include "vehicle.h"
#include "lidar.h"

dirside_t	dirside_set(lidar_t *this)
{
	if (lidar_sides_over_center(this) && lidar_lean_left(this))
		return (DS_LEFT);
	else if (lidar_sides_over_center(this) && lidar_lean_right(this))
		return (DS_RIGHT);
	else
		return (DS_CENTER);
}

vehicle_t	*direction_set_side(vehicle_t *this)
{
	if (this->dirside == DS_RIGHT)
		this->direction *= -1;
	else if (this->dirside == DS_CENTER)
		this->direction = 0.0f;
	return (this);
}
