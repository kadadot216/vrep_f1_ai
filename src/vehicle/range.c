/*
** EPITECH PROJECT, 2018
** range.c
** File description:
** Range related functions
*/

#include <stdio.h>

#include "vehicle.h"

int	lidar_sides_over_center(lidar_t *this)
{
	return ((this->center < this->left_corner) ||
		(this->center < this->right_corner));
}

int	lidar_lean_left(lidar_t *this)
{
	return (this->left_corner > this->right_corner);
}

int	lidar_lean_right(lidar_t *this)
{
	return (this->right_corner > this->left_corner);
}


dirside_t	dirside_set(lidar_t *this)
{
	if (lidar_sides_over_center(this) && lidar_lean_left(this))
		return (DS_LEFT);
	else if (lidar_sides_over_center(this) && lidar_lean_right(this))
		return (DS_RIGHT);
	else
		return (DS_CENTER);
}

int	lidar_in_range(float *lidar_pt, float *range_max, float *range_min)
{
	return ((*lidar_pt) >= (*range_min) && (*lidar_pt) < (*range_max));;
}

vehicle_t	*direction_set_side(vehicle_t *this)
{
	if (this->dirside == DS_RIGHT)
		this->direction *= -1;
	else if (this->dirside == DS_CENTER)
		this->direction = 0.0f;
	return (this);
}

vehicle_t	*vehicle_update_params(vehicle_t *this)
{
	float	ranges[DRANGE_SIZE] = {
			DRANGE_0, DRANGE_1, DRANGE_2, DRANGE_3,
			DRANGE_4, DRANGE_5, DRANGE_6, DRANGE_7};
	float	speeds[SPEEDS] = {SPEED_1, SPEED_2, SPEED_3, SPEED_4, SPEED_5, SPEED_6, SPEED_7};
	float	steers[STEERS] = {STEER_1, STEER_2, STEER_3, STEER_4, STEER_5, STEER_6, STEER_7};
	int	i = 1;
	float	*center = &this->lidar.center;

	this->dirside = dirside_set(&this->lidar);
	while (i < DRANGE_SIZE) {
		dprintf(2, "Range %d = %f, range %d = %f\n", (i - 1), ranges[i - 1], i, ranges[i]);
		if (lidar_in_range(center, &ranges[i - 1], &ranges[i])) {
			this->speed = speeds[i - 1];
			this->direction = steers[i - 1];
		}
		i++;
	}
	this = direction_set_side(this);
	return (this);
}
