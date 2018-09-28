/*
** EPITECH PROJECT, 2018
** range.c
** File description:
** Range related functions
*/

#include <stdio.h>

#include "vehicle.h"
#include "lidar.h"

vehicle_t	*vehicle_update_params(vehicle_t *this)
{
	float	ranges[DRANGE_SIZE] = {DRANGE_1, DRANGE_2, DRANGE_3, DRANGE_4,
		DRANGE_5, DRANGE_6, DRANGE_7, DRANGE_0};
	float	speeds[SPEEDS] = {SPEED_1, SPEED_2, SPEED_3, SPEED_4, SPEED_5,
		SPEED_6, SPEED_0};
	float	steers[STEERS] = {STEER_1, STEER_2, STEER_3, STEER_4, STEER_5,
		STEER_6, STEER_0};
	int	idx = 1;
	float	*center = &this->lidar.center;

	this = vehicle_set_dirside(this, dirside_set(&this->lidar));
	while (idx < DRANGE_SIZE) {
		if (lidar_in_range(center, &ranges[idx - 1], &ranges[idx])) {
			this = vehicle_set_speed(this, speeds[idx - 1]);
			this = vehicle_set_direction(this, steers[idx - 1]);
			this = direction_set_side(this);
			return (this);
		}
		idx++;
	}
	return (this);
}
