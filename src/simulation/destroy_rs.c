/*
** EPITECH PROJECT, 2018
** destroy_rs.c
** File description:
** Simulation destroy routines
*/

#include "simulation.h"

void	simulation_destroy_assets(command_t *sim, callback_t *cb)
{
	sim = command_table_destroy(sim, SIM_ACTIONS_SIZE);
	cb->ref = callback_col_free(cb->ref);
	cb = callback_unset(cb);
}
