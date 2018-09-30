/*
** EPITECH PROJECT, 2018
** changeflags.c
** File description:
** Changeflags functions
*/

#include "vehicle.h"

vehicle_t	*vehicle_reset_changeflag(vehicle_t *this)
{
	this = vehicle_set_changeflag(this, C_NONE);
	return (this);
}

int	is_speed_flag_set(vehicle_t *this)
{
	return (this->change == C_SPEED);
}

int	is_both_flags_set(vehicle_t *this)
{
	return (this->change == C_BOTH);
}

int	is_dir_flag_set(vehicle_t *this)
{
	return (this->change == C_DIR);
}
