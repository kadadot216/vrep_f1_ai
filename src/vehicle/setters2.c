#include "vehicle.h"

vehicle_t	*vehicle_set_changeflag(vehicle_t *this, changeflag_t flag)
{
	this->change = flag;
	return (this);
}
