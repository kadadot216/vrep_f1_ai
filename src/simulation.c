/*
** EPITECH PROJECT, 2018
** simulation.c
** File description:
** Simulation handling functions
*/

#include "command.h"
#include "callback.h"
#include "need4stek.h"

int	n4s_track_cleared(callback_t *c, command_t *siminfo)
{
	c = callback_set_rtype(c, RES_SIMTIME);
	callback_getcmd(c, siminfo);
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}

command_t	*get_simtab(void)
{
	int	index = 0;
	command_t	*simtab = NULL;
	command_t	data[SIM_ACTIONS_SIZE] = {
		cmd_entry(START_SIMULATION, C_START_SIMULATION, V_NONE, 1),
		cmd_entry(STOP_SIMULATION, C_STOP_SIMULATION, V_NONE, 1),
		cmd_entry(CYCLE_WAIT, C_CYCLE_WAIT, V_INT, 3),
		cmd_entry(GET_INFO_SIMTIME, C_GET_INFO_SIMTIME, V_NONE, 4)
	};
	simtab = malloc(sizeof(command_t) * SIM_ACTIONS_SIZE);
	while (index < SIM_ACTIONS_SIZE) {
		simtab[index] = data[index];
		index++;
	}
	return (simtab);
}
