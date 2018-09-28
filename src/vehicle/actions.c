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
	dprintf(2, "\t\t%f", this->left_corner);
	dprintf(2, "\t\t%f", this->left_side);
	dprintf(2, "\t\t%f", this->center);
	dprintf(2, "\t\t%f", this->right_side);
	dprintf(2, "\t\t%f", this->right_corner);
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

vehicle_t	*vehicle_getinfos(vehicle_t *this, callback_t *cb)
{
	// Faire qqchose pour mapper le lidar à partir de
	// du message de collection
	// Prototype (callback_t *, callback_col_t, line)
	cb->rtype = RES_LIDAR;
	callback_getcmd(cb, &this->getinfo[GET_INFO_LIDAR]);
	this = vehicle_update_lidar(this, cb);
	cb->rtype = RES_FEEDBACK;
	callback_getcmd(cb, &this->getinfo[GET_CURRENT_SPEED]);
	this = vehicle_update_speed(this, cb);
	cb->rtype = RES_FEEDBACK;
	callback_getcmd(cb, &this->getinfo[GET_CURRENT_WHEELS]);
	this = vehicle_update_direction(this, cb);
	return (this);
}
