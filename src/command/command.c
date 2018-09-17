/*
** EPITECH PROJECT, 2018
** command.c
** File description:
** Command related functions
*/

#include "my.h"
#include "need4stek.h"

command_t	*command_table_init(void)
{
	int	index = 0;
	command_t	data[CMDNAME_SIZE] = {
		{0, my_strdup("START_SIMULATION"), NULL, 1},
		{1, my_strdup("STOP_SIMULATION"), NULL, 1},
		{2, my_strdup("CAR_FORWARD"), my_fnew(), 1},
		{3, my_strdup("CAR_BACKWARDS"), my_fnew(), 1},
		{4, my_strdup("WHEELS_DIR"), my_fnew(), 1},
		{5, my_strdup("GET_INFO_LIDAR"), NULL, 2},
		{6, my_strdup("GET_CURRENT_SPEED"), NULL, 3},
		{7, my_strdup("GET_CURRENT_WHEELS"), NULL, 3},
		{8, my_strdup("CYCLE_WAIT"), my_fnew(), 3},
		{9, my_strdup("GET_CAR_SPEED_MAX"), NULL, 3},
		{10, my_strdup("GET_CAR_SPEED_MIN"), NULL, 3},
		{11, my_strdup("GET_INFO_SIMTIME"), NULL, 4}
	};
	command_t	*cmdt = malloc(sizeof(command_t) * CMDNAME_SIZE);
	while (index++ < CMDNAME_SIZE)
		cmdt[index] = data[index];
	return (cmdt);
}

command_t	*command_table_destroy(command_t *this)
{
	int	index = 0;

	while (index < CMDNAME_SIZE) {
		this[index].name = 0;
		free(this[index].prefix);
		this[index].prefix = NULL;
		if (this[index].value != NULL) {
			*(this[index].value) = 0.0;
			free(this[index].value);
			this[index].value = NULL;
		}
		this[index].rtype = RES_NIL;
		index++;
	}
	free(this);
	this = NULL;
	return (this);
}
