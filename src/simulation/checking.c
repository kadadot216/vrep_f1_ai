#include <stdio.h>
#include "simulation.h"

int	n4s_track_cleared(callback_t *c, command_t *action)
{
	c = callback_set_rtype(c, RES_LIDAR);
	callback_getcmd(c, action);
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}

int	vehicle_too_close(vehicle_t *this)
{
	return (this->speed == SPEED_0);
}
