#include "need4stek.h"
#include "vehicle.h"

vehicle_t	*vehicle_update_speed(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_speed(this, cb->rvals.fbk);
	return (this);
}

vehicle_t	*vehicle_update_direction(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_direction(this, cb->rvals.fbk);
	return (this);
}

vehicle_t	*vehicle_update_lidar(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_lidar(this, cb->rvals.lidar);
	return (this);
}

vehicle_t	*vehicle_update_actions(vehicle_t *this)
{
	this->action[CAR_FORWARD].value->f = this->speed;
	this->action[CAR_BACKWARDS].value->f = (- this->speed);
	this->action[WHEELS_DIR].value->f = this->direction;
	return (this);
}
