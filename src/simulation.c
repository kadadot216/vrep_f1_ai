/*
** EPITECH PROJECT, 2018
** simulation.c
** File description:
** Simulation handling functions
*/

#include "command.h"
#include "need4stek.h"

command_t	*get_simtab(void)
{
	int	index = 0;
	command_t	*simtab = NULL;
	command_t	data[SIM_ACTIONS_SIZE] = {
		{START_SIMULATION, my_strdup(C_START_SIMULATION), NULL, 1},
		{STOP_SIMULATION, my_strdup(C_STOP_SIMULATION), NULL, 1},
		{CYCLE_WAIT, my_strdup(C_CYCLE_WAIT), my_fnew(), 3},
		{SIM_ACTIONS_SIZE, my_strdup(C_GET_INFO_SIMTIME), NULL, 4}
	};
	simtab = malloc(sizeof(command_t) * SIM_ACTIONS_SIZE);
	while (index < SIM_ACTIONS_SIZE) {
		simtab[index] = data[index];
		index++;
	}
	return (simtab);
}
