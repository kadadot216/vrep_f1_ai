/*
** EPITECH PROJECT, 2018
** command.c
** File description:
** Command related functions
*/

#include "my.h"
#include "need4stek.h"
#include "command.h"

command_t	*command_destroy_value(command_t *this)
{
	if (this->vtype == V_NONE)
		return (this);
	else if (this->vtype == V_INT)
		this->value->i = 0;
	else if (this->vtype == V_FLOAT)
		this->value->f = 0.0f;
	free(this->value);
	this->value = NULL;
	return (this);
}

command_t	*ctab_destroy(command_t *this, int size)
{
	int	index = 0;

	while (index < size) {
		this[index].name = 0;
		free(this[index].prefix);
		this[index].prefix = NULL;
		command_destroy_value(&this[index]);
		this[index].vtype = V_NONE;
		this[index].rtype = RES_NIL;
		index++;
	}
	free(this);
	this = NULL;
	return (this);
}
