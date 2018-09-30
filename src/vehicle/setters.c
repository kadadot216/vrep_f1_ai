#include "vehicle.h"
#include "command.h"
#include "lidar.h"

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
