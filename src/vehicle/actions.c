/*
** EPITECH PROJECT, 2018
** actions.c
** File description:
** Vehicle actions tab 
*/

#include <stdlib.h>

#include <stdio.h>
#include "vehicle.h"
#include "callback.h"
#include "command.h"

void	print_lidar(lidar_t *this)
{
	dprintf(2, "\t\t%f", this->left_side);
	dprintf(2, "\t\t%f", this->center);
	dprintf(2, "\t\t%f", this->right_side);
}

void	print_vehicle_infos(vehicle_t *this)
{
	dprintf(2, "Vehicle: {\n"
		"\tSpeed: %f\n"
		"\tDir: %f\n"
		"\tLidar: {", this->speed, this->direction);
	print_lidar(&this->lidar);
	dprintf(2, "}\n");
}

vehicle_t	*vehicle_observe(vehicle_t *this, callback_t *cb)
{
	cb = callback_set_rtype(cb, RES_LIDAR);
	callback_getcmd(cb, &this->getinfo[GET_INFO_LIDAR]);
	this = vehicle_update_lidar(this, cb);
	return (this);
}
