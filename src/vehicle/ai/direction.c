/*
** EPITECH PROJECT, 2018
** compute_direction.c
** File description:
** Compute and update the direction according to the lidar
*/

#include <stdio.h>	//delet

#include "vehicle.h"

float	ai_set_direction(vehicle_t *this)
{
	int	index = 0;
	int	imax = 0;
	float	(*corner_ptr[LIDAR_ANGLES]) = {
		&this->lidar.left_corner,
		&this->lidar.left_side,
		&this->lidar.center,
		&this->lidar.right_side,
		&this->lidar.right_corner,
	};
	float	*furthest_pt = corner_ptr[0];
	float	new_direction = 0.0f;

	while (index < LIDAR_ANGLES) {
		if ((*corner_ptr[index]) > (*furthest_pt) && (*corner_ptr[index]) > 400.0f) {
			furthest_pt = corner_ptr[index];
			imax = index;
		}
		index++;
	}
	new_direction = (- ((imax + 1) * WHEEL_TICK)) + 0.4f;	// - 1.0f + (0.2f pour compenser le nb impair d'angles)
	return (new_direction);
}
