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
	int	i = 0;
	float	ptmax = 0.0f;
	int	imax = i;
	int	interval = 1;
	float	pot_direction = 0.0f;
	float	new_direction = 0.0f;

	//while (i < LRES_SIZE) {
	//	dprintf(2, "lidar[%u] = %f\n", i, this->lidar[i]);
	//	if (this->lidar[i] > ptmax) {
	//		ptmax = this->lidar[i];
	//		imax = i;
	//		interval = 1;
	//	} else if (this->lidar[i] == ptmax)
	//		interval++;
	//	i++;
	//}
	//imax += (interval / 2);
	dprintf(2, "%d <=> final direction = %d\n", interval, imax);
	pot_direction = (- ((imax * WHEEL_TICK) - 1.0f));
	if (pot_direction > 0.2 || pot_direction < - 0.2)
		new_direction = pot_direction;
	dprintf(2, "New direction = %f\n", new_direction);
	return (new_direction);
}
