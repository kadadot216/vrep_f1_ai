#include <stdio.h>

#include "vehicle.h"
#include "lidar.h"
#include "ai.h"

static vehicle_t	*ai_update_from_range(vehicle_t *this, float *data,
vehicle_t *(*op)(vehicle_t *, float))
{
	int	idx = 1;
	float	*center = &this->lidar.center;
	float	ranges[DRANGE_SIZE] = {DRANGE_1, DRANGE_2, DRANGE_3, DRANGE_4,
		DRANGE_5, DRANGE_6, DRANGE_7, DRANGE_0};

	while (idx < DRANGE_SIZE) {
		if (lidar_in_range(center, &ranges[idx - 1], &ranges[idx])) {
			this = op(this, data[idx - 1]);
			return (this);
		}
		idx++;
	}
	return (this);
}

vehicle_t	*ai_update_direction(vehicle_t *this)
{
	float	dirs[DIR_SIZE] = {DIR_1, DIR_2, DIR_3, DIR_4, DIR_5,
		DIR_6, DIR_0};
	changeflag_t	flag_to_set = C_DIR;

	this = vehicle_set_dirside(this, dirside_set(&this->lidar));
	this = ai_update_from_range(this, dirs, vehicle_set_direction);
	this = direction_set_side(this);
	if (is_speed_flag_set(this))
		flag_to_set = C_BOTH;
	vehicle_set_changeflag(this, flag_to_set);
	return (this);
}

int	is_speed_changed(vehicle_t *this, float old_speed)
{
	if (old_speed == this->speed) {
		return (0);
	} else if (old_speed != this->speed) {
		return (1);
	}
	return (0);
}

vehicle_t	*ai_update_speed(vehicle_t *this)
{
	float	old_speed = this->speed;
	float	speeds[SPEED_SIZE] = {SPEED_1, SPEED_2, SPEED_3, SPEED_4,
		SPEED_5, SPEED_6, SPEED_0};

	this = ai_update_from_range(this, speeds, vehicle_set_speed);
	if (is_speed_changed(this, old_speed)) {
		vehicle_set_changeflag(this, C_SPEED);
	}
	return (this);
}
