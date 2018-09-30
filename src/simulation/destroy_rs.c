/*
** EPITECH PROJECT, 2018
** destroy_rs.c
** File description:
** Simulation destroy routines
*/

#include "simulation.h"

void	simulation_destroy_assets(sim_t *sim, callback_t *cb)
{
	sim = sim_destroy(sim);
	cb->ref = callback_col_free(cb->ref);
	cb = callback_unset(cb);
}
