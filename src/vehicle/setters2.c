/*
** EPITECH PROJECT, 2018
** setters2.c
** File description:
** Setters related functions
*/

#include "vehicle.h"

vehicle_t	*vehicle_set_changeflag(vehicle_t *this, changeflag_t flag)
{
	this->change = flag;
	return (this);
}
