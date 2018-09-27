/*
** EPITECH PROJECT, 2018
** command.h
** File description:
** Header file for Command functions
*/

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "api.h"

typedef	enum	e_valtype {
	V_NONE,
	V_INT,
	V_FLOAT
}	valtype_t;

typedef union	u_cmdvalue {
	int	i;
	float	f;
}	cmdvalue_t;

typedef	struct	s_command {
	cmdname_t	name;
	char		*prefix;
	valtype_t	vtype;
	cmdvalue_t	*value;
	api_rtype_t	rtype;
}	command_t;

void	command_psend(char const *cmd, float *value);
void	command_send(command_t *this);
command_t	cmd_entry(cmdname_t name, char *prefix,
valtype_t type, api_rtype_t rtype);
cmdvalue_t	*cmdval_new(valtype_t vtype);
command_t	*command_table_destroy(command_t *this); //delete
command_t	*command_table_init(void);		//delete
command_t	*ctab_destroy(command_t *this, int size);
command_t	*get_simtab(void);

#endif /* __COMMAND_H__ */
