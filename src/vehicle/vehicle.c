#include "need4stek.h"
#include "vehicle.h"

vehicle_t	*vehicle_reset(vehicle_t *this)
{
	this = vehicle_set_speed(this, 0.0f);
	this = vehicle_set_direction(this, 0.0f);
	this = vehicle_set_empty_lidar(this);
	this = vehicle_set_dirside(this, DS_CENTER);
	this->action = NULL;
	this->getinfo = NULL;
	return (this);
}

vehicle_t	*vehicle_destroy(vehicle_t *this)
{
	this->action = command_table_destroy(this->action, CAR_ACTION_SIZE);
	this->getinfo = command_table_destroy(this->getinfo, CAR_INFOACT_SIZE);
	this = vehicle_reset(this);
	return (this);
}

vehicle_t	vehicle_new(void)
{
	vehicle_t	new;

	vehicle_reset(&new);
	vehicle_init_actions(&new);
	vehicle_init_getinfos(&new);
	return (new);
}
