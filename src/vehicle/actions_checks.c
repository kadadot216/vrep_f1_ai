#include "vehicle.h"

int	vehicle_can_change_speed(vehicle_t *this)
{
	return (is_speed_flag_set(this) || is_both_flags_set(this));
}

int	vehicle_can_change_dir(vehicle_t *this)
{
	return (is_dir_flag_set(this) || is_both_flags_set(this));
}
