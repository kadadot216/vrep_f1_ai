/*
** EPITECH PROJECT, 2018
** compose.c
** File description:
** Command composition function
*/

#include <stdio.h>
#include "command.h"

void	command_send(command_t *this)
{
	if (this->vtype == V_INT)
		dprintf(1, "%s:%d\n", this->prefix, this->value->i);
	else if (this->vtype == V_FLOAT)
		dprintf(1, "%s:%f\n", this->prefix, this->value->f);
	else
		dprintf(1, "%s\n", this->prefix);
}
