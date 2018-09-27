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
	dprintf(2, "new direction = %f\n", this->direction);
	if (this->direction >= -0.4 && this->direction <= 0.4) {
		new_speed = 0.3f;
	} else if (this->direction < (- 0.4) || this->direction > 0.4) {
		new_speed = 0.1f;
	}
	dprintf(2, "New speed = %f\n", new_speed);
	return (new_speed);
}
