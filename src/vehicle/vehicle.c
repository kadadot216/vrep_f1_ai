/*
** EPITECH PROJECT, 2018
** vehicle.c
** File description:
** Vehicle related functions
*/

#include "need4stek.h"
#include "vehicle.h"
#include "command.h"

vehicle_t	*vehicle_reset(vehicle_t *this)
{
	this = vehicle_set_speed(this, 0.0f);
	this = vehicle_set_direction(this, 0.0f);
	this = vehicle_set_empty_lidar(this);
	this->action = NULL;
	this->getinfo = NULL;
	return (this);
}

vehicle_t	*vehicle_destroy(vehicle_t *this)
{
	this->action = ctab_destroy(this->action, CAR_ACTION_SIZE);
	this->getinfo = ctab_destroy(this->getinfo, CAR_INFOACT_SIZE);
	this = vehicle_reset(this);
	return (this);
}

vehicle_t	vehicle_new(void)
{
	vehicle_t	new;

	vehicle_reset(&new);
	vehicle_set_actions(&new);
	vehicle_set_getinfos(&new);
	return (new);
}
