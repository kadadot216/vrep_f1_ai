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
	if (this->vtype == V_INT)
		this->value->i = 0;
	else if (this->vtype == V_FLOAT)
		this->value->f = 0.0f;
	free(this->value);
	this->value = NULL;
	return (this);
}

command_t	*cmd_destroy(command_t *this)
{
	this->name = 0;
	free(this->prefix);
	this->prefix = NULL;
	this = command_destroy_value(this);
	this->vtype = V_NONE;
	this->rtype = RES_NIL;
	return (this);
}

command_t	*command_table_destroy(command_t *this, int size)
{
	int	index = 0;

	while (index < size) {
		cmd_destroy(&this[index]);
		index++;
	}
	free(this);
	this = NULL;
	return (this);
}
