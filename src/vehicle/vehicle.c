/*
** EPITECH PROJECT, 2018
** vehicle.c
** File description:
** Vehicle related functions
*/

#include "need4stek.h"


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

vehicle_t	*vehicle_reset(vehicle_t *this)
{
	float	empty_lidar[LRES_SIZE] = { 0.0f };

	this = vehicle_set_speed(this, 0.0f);
	this = vehicle_set_direction(this, 0.0f);
	this = vehicle_set_lidar(this, empty_lidar);
	return (this);
}

vehicle_t	vehicle_new(void)
{
	vehicle_t	new;

	vehicle_reset(&new);
	return (new);
}
