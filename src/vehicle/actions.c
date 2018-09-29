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

vehicle_t	*vehicle_observe(vehicle_t *this, callback_t *cb)
{
	cb = callback_set_rtype(cb, RES_LIDAR);
	callback_getcmd(cb, &this->getinfo[GET_INFO_LIDAR]);
	this = vehicle_update_lidar(this, cb);
	return (this);
}
