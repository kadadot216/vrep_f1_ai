/*
** EPITECH PROJECT, 2018
** command.c
** File description:
** Command related functions
*/

#include "my.h"
#include "need4stek.h"
#include "command.h"

command_t	*command_table_init(void)
{
	int	index = 0;
	command_t	data[12] = {
		{0, my_strdup(C_START_SIMULATION), NULL, 1},
		{1, my_strdup(C_STOP_SIMULATION), NULL, 1},
		{2, my_strdup(C_CAR_FORWARD), my_fnew(), 1},
		{3, my_strdup(C_CAR_BACKWARDS), my_fnew(), 1},
		{4, my_strdup(C_WHEELS_DIR), my_fnew(), 1},
		{5, my_strdup(C_GET_INFO_LIDAR), NULL, 2},
		{6, my_strdup(C_GET_CURRENT_SPEED), NULL, 3},
		{7, my_strdup(C_GET_CURRENT_WHEELS), NULL, 3},
		{8, my_strdup(C_CYCLE_WAIT), my_fnew(), 3},
		{9, my_strdup(C_GET_CAR_SPEED_MAX), NULL, 3},
		{10, my_strdup(C_GET_CAR_SPEED_MIN), NULL, 3},
		{11, my_strdup(C_GET_INFO_SIMTIME), NULL, 4}
	};
	command_t	*cmdt = malloc(sizeof(command_t) * 12);
	while (index < 12) {
		cmdt[index] = data[index];
		index++;
	}
	return (cmdt);
}

command_t	*ctab_destroy(command_t *this, int size)
{
	int	index = 0;

	while (index < size) {
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

command_t	*command_table_destroy(command_t *this)
{
	int	index = 0;

	while (index < 12) {
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
