/*
** EPITECH PROJECT, 2018
** setters.c
** File description:
** Setters related functions
*/

#include "vehicle.h"

vehicle_t	*vehicle_set_speed(vehicle_t *this, float speed)
{
	this->speed = speed;
	return (this);
}

vehicle_t	*vehicle_set_direction(vehicle_t *this, float wheels)
{
	this->direction = wheels;
	return (this);
}

vehicle_t	*vehicle_set_lidar(vehicle_t *this, float *lidar)
{
	int	index = 0;

	while (index < LRES_SIZE) {
		this->lidar[index] = lidar[index];
		index++;
	}
	return (this);
}

vehicle_t	*vehicle_set_actions(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_ACTION_SIZE] = {
		{CAR_FORWARD, my_strdup("CAR_FORWARD"), my_fnew(), 1},
		{CAR_BACKWARDS, my_strdup("CAR_BACKWARDS"), my_fnew(), 1},
		{WHEELS_DIR, my_strdup("WHEELS_DIR"), my_fnew(), 1}
	};
	while (index < CAR_ACTION_SIZE) {
		this->action[index] = data[index];
		*(this->action[index].value) = 0.0f;
		index++;
	}
	return (this);
}

vehicle_t	*vehicle_set_getinfos(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_INFOACT_SIZE] = {
		{GET_INFO_LIDAR, my_strdup("GET_INFO_LIDAR"), NULL, 2},
		{GET_CURRENT_SPEED, my_strdup("GET_CURRENT_SPEED"), NULL, 2},
		{GET_CURRENT_WHEELS, my_strdup("GET_CURRENT_WHEELS"), NULL, 2},
		{GET_CAR_SPEED_MAX, my_strdup("GET_CAR_SPEED_MAX"), NULL, 2},	// Non pour l'instant
		{GET_CAR_SPEED_MIN, my_strdup("GET_CAR_SPEED_MIN"), NULL, 2}
	};
	while (index < CAR_INFOACT_SIZE) {
		this->getinfo[index] = data[index];
		index++;
	}
	return (this);
}
