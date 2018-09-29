/*
** EPITECH PROJECT, 2018
** getcmd.c
** File description:
** Callback commands interaction
*/

#include <stdio.h>
#include "callback.h"
#include "command.h"

callback_t	*callback_getcmd(callback_t *this, command_t *command)
{
	char		*raw_res = NULL;
	size_t		n = 0;

	command_send(command);
	getline(&raw_res, &n, stdin);
	callback_get_parts(this, raw_res);
	free(raw_res);
	return (this);
}
