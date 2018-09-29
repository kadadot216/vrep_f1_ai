/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** Simulation tab creation function
*/

#include "simulation.h"

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
