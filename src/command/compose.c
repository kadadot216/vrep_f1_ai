/*
** EPITECH PROJECT, 2018
** compose.c
** File description:
** Command composition function
*/

#include <stdio.h>
#include "command.h"

void	command_psend(char const *cmd, float *value)
{
	if (value)
		dprintf(1, "%s:%f\n", cmd, *value);
	else
		dprintf(1, "%s\n", cmd);
}

void	command_send(command_t *this)
{
	command_psend(this->prefix, this->value);
}
