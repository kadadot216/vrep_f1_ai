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

lidar_t		*lidar_set(lidar_t *this, float *tab)
{
	this->left_side = tab[LIDAR_LSIDE];
	this->center = tab[LIDAR_CENTER];
	this->right_side = tab[LIDAR_RSIDE];
	return (this);
}

vehicle_t	*vehicle_set_lidar(vehicle_t *this, float *lidar_tab)
{
	lidar_set(&this->lidar, lidar_tab);
	return (this);
}

vehicle_t	*vehicle_set_empty_lidar(vehicle_t *this)
{
	float	empty_lidar[LRES_SIZE] = { 0.0f };

	this = vehicle_set_lidar(this, empty_lidar);
	return (this);
}

vehicle_t	*vehicle_set_dirside(vehicle_t *this, dirside_t side)
{
	this->dirside = side;
	return (this);
}

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
