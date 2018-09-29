/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Vehicle initialization functions
*/

#include "vehicle.h"

vehicle_t	*vehicle_init_actions(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_ACTION_SIZE] = {
		cmd_entry(CAR_FORWARD, C_CAR_FORWARD, V_FLOAT, 1),
		cmd_entry(CAR_BACKWARDS, C_CAR_BACKWARDS, V_FLOAT, 1),
		cmd_entry(WHEELS_DIR, C_WHEELS_DIR, V_FLOAT, 1)
	};
	this->action = malloc(sizeof(command_t) * CAR_ACTION_SIZE);
	while (index < CAR_ACTION_SIZE) {
		this->action[index] = data[index];
		this->action[index].value->f = 0.0f;
		index++;
	}
	return (this);
}

vehicle_t	*vehicle_init_getinfos(vehicle_t *this)
{
	int	index = 0;
	command_t	data[CAR_INFOACT_SIZE] = {
		cmd_entry(GET_INFO_LIDAR, C_GET_INFO_LIDAR, V_NONE, 2),
		cmd_entry(GET_CURRENT_SPEED, C_GET_CURRENT_SPEED, V_NONE, 2),
		cmd_entry(GET_CURRENT_WHEELS, C_GET_CURRENT_WHEELS, V_NONE, 2),
		cmd_entry(GET_CAR_SPEED_MAX, C_GET_CAR_SPEED_MAX, V_NONE, 2),
		cmd_entry(GET_CAR_SPEED_MIN, C_GET_CAR_SPEED_MIN, V_NONE, 2)
	};
	this->getinfo = malloc(sizeof(command_t) * CAR_INFOACT_SIZE);
	while (index < CAR_INFOACT_SIZE) {
		this->getinfo[index] = data[index];
		index++;
	}
	return (this);
}
