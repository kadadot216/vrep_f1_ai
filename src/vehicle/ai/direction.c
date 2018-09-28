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
	float	new_direction = 0.0f;
	int 	coeff = 1;

	//if (this->lidar.left_side > this->lidar.center && this->lidar.left_side > this->lidar.right_side && this->lidar.left_corner > TOO_CLOSE) {
	//	new_direction = WHEEL_TICK;
	//} else if (this->lidar.right_side > this->lidar.center && this->lidar.left_side < this->lidar.right_side && this->lidar.right_corner > TOO_CLOSE) {
	//	new_direction = -WHEEL_TICK;
	//}
	//if (this->lidar.right_side < TOO_CLOSE) {
	//	new_direction = WHEEL_TICK;
	//} else if (this->lidar.left_side) {
	//	new_direction = -WHEEL_TICK;
	//}
	return (new_direction);
}
