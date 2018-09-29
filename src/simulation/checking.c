/*
** EPITECH PROJECT, 2018
** checking.c
** File description:
** Simulation checking functions
*/

#include "simulation.h"

int	n4s_track_cleared(callback_t *c, command_t *siminfo)
{
	c = callback_set_rtype(c, RES_SIMTIME);
	callback_getcmd(c, siminfo);
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}
