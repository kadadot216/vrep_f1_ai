/*
** EPITECH PROJECT, 2018
** setters.c
** File description:
** Setters related functions
*/

#include "vehicle.h"
#include "command.h"

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

vehicle_t	*vehicle_set_empty_lidar(vehicle_t *this)
{
	float	empty_lidar[LRES_SIZE] = { 0.0f };

	this = vehicle_set_lidar(this, empty_lidar);
	return (this);
}

vehicle_t	*vehicle_init_actions(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_ACTION_SIZE] = {
		{CAR_FORWARD, my_strdup(C_CAR_FORWARD), my_fnew(), 1},
		{CAR_BACKWARDS, my_strdup(C_CAR_BACKWARDS), my_fnew(), 1},
		{WHEELS_DIR, my_strdup(C_WHEELS_DIR), my_fnew(), 1}
	};
	this->action = malloc(sizeof(command_t) * CAR_ACTION_SIZE);
	while (index < CAR_ACTION_SIZE) {
		this->action[index] = data[index];
		*(this->action[index].value) = 0.0f;
		index++;
	}
	return (this);
}

vehicle_t	*vehicle_init_getinfos(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_INFOACT_SIZE] = {
		{GET_INFO_LIDAR, my_strdup(C_GET_INFO_LIDAR), NULL, 2},
		{GET_CURRENT_SPEED, my_strdup(C_GET_CURRENT_SPEED), NULL, 2},
		{GET_CURRENT_WHEELS, my_strdup(C_GET_CURRENT_WHEELS), NULL, 2},
		{GET_CAR_SPEED_MAX, my_strdup(C_GET_CAR_SPEED_MAX), NULL, 2},	// Non pour l'instant
		{GET_CAR_SPEED_MIN, my_strdup(C_GET_CAR_SPEED_MIN), NULL, 2}
	};
	this->getinfo = malloc(sizeof(command_t) * CAR_INFOACT_SIZE);
	while (index < CAR_INFOACT_SIZE) {
		this->getinfo[index] = data[index];
		index++;
	}
	return (this);
}
