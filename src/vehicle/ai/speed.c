/*
** EPITECH PROJECT, 2018
** compute_speed.c
** File description:
** Lidar compute functions
*/

#include <stdio.h>	//delet

#include "vehicle.h"

float	ai_set_speed(vehicle_t *this)
{
	float	new_speed = 0.0f;
	if (this->direction >= -0.125 || this->direction <= 0.125) {
		new_speed = 0.6f;
	} else if (this->direction < -0.125 || this->direction > 0.125) {
		new_speed = 0.2f;
	}
	dprintf(2, "New speed = %f\n", new_speed);
	return (new_speed);
}
