/*
** EPITECH PROJECT, 2018
** actions.c
** File description:
** Vehicle actions tab 
*/

#include "vehicle.h"
#include "ai.h"
#include "callback.h"

vehicle_t	*vehicle_observe(vehicle_t *this, callback_t *cb)
{
	cb = callback_set_rtype(cb, RES_LIDAR);
	callback_getcmd(cb, &this->getinfo[GET_INFO_LIDAR]);
	this = vehicle_update_lidar(this, cb);
	return (this);
}

void	vehicle_change_speed(vehicle_t *vehicle, callback_t *cb)
{
	if (vehicle_can_change_speed(vehicle))
		callback_getcmd(cb, &vehicle->action[CAR_FORWARD]);
}

void	vehicle_change_dir(vehicle_t *vehicle, callback_t *cb)
{
	if (vehicle_can_change_dir(vehicle))
		callback_getcmd(cb, &vehicle->action[WHEELS_DIR]);
}

void	vehicle_dispatch_actions(vehicle_t *vehicle, callback_t *cb)
{
	vehicle = vehicle_update_actions(vehicle);
	vehicle_change_speed(vehicle, cb);
	vehicle_change_dir(vehicle, cb);
	vehicle = vehicle_reset_changeflag(vehicle);
}

void	ai_update_vehicle(vehicle_t *vehicle)
{
	vehicle = ai_update_speed(vehicle);
	vehicle = ai_update_direction(vehicle);
}
