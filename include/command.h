/*
** EPITECH PROJECT, 2018
** command.h
** File description:
** Header file for Command functions
*/

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "api.h"

typedef	struct	s_command {
	cmdname_t	name;
	char		*prefix;
	float		*value;
	api_rtype_t	rtype;
}	command_t;

void	command_psend(char const *cmd, float *value);
void	command_send(command_t *this);
command_t	*command_table_destroy(command_t *this); //delete
command_t	*command_table_init(void);		//delete
command_t	*ctab_destroy(command_t *this, int size);
command_t	*get_simtab(void);

#endif /* __COMMAND_H__ */
