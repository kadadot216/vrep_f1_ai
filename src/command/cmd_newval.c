#include <stdlib.h>
#include "command.h"
#include "my.h"

cmdvalue_t	*cmdval_new(valtype_t vtype)
{
	cmdvalue_t	*new = NULL;

	new = malloc(sizeof(cmdvalue_t));
	if (!new)
		return (NULL);
	if (vtype == V_INT) {
		new->i = 0;
		return (new);
	}
	new->f = 0.0f;
	return (new);
}

command_t	cmd_entry(cmdname_t name, char *prefix,
valtype_t type, api_rtype_t rtype)
{
	command_t	new;

	new.name = name;
	new.prefix = NULL;
	new.prefix = my_strdup(prefix);
	new.vtype = type;
	new.value = NULL;
	new.value = cmdval_new(type);
	new.rtype = rtype;
	return (new);
}
