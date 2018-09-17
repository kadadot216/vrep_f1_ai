/*
** EPITECH PROJECT, 2018
** compose.c
** File description:
** Command composition function
*/

#include <stdio.h>
#include "need4stek.h"

void	command_psend(char const *cmd, float *value)
{
	if (value)
		printf("%s:%f\n", cmd, *value);
	else
		printf("%s\n", cmd);
}

void	command_send(command_t *this)
{
	command_psend(this->prefix, this->value);
}
