/*
** EPITECH PROJECT, 2018
** callback.c
** File description:
** callback actions for addinfo structure
*/

#include "my.h"
#include "need4stek.h"

callback_t	*callback_get_code(callback_t *this, char *line)
{
	this->code = ((api_code_t) my_getnbr(line));
	return (this);
}

callback_t	*callback_get_status(callback_t *this, char *line)
{
	this->status = (my_strn_eq(line, "OK")) ? OK : KO;
	return (this);
}

callback_t	*callback_get_code_str(callback_t *this, char *line)
{
	char	*code_str_ref = this->ref->l_code_str[this->code];

	if (my_strn_eq(line, code_str_ref))
		this->code_str = code_str_ref;
	return (this);
}

callback_t	*callback_get_addinfo(callback_t *this, char *line)
{
	int	i = 0;
	char	**addinfo_ref = this->ref->l_addinfo;

	while (i < ADDINFO_PTS) {
		if (my_strn_eq(line, addinfo_ref[i])) {
			this->addinfo = addinfo_ref[i];
			return (this);
		}
		i++;
	}
	return (this);
}

callback_t	*callback_get_rvals(callback_t *this, char *line)
{
	if (this->rtype == RES_LIDAR) {
		this->rvals = rvals_get_lidar(this, line);
	} else if (this->rtype == RES_FEEDBACK) {
		this->rvals = rvals_get_feedback(this, line);
	} else if (this->rtype == RES_SIMTIME) {
		this->rvals = rvals_get_stime(this, line);
	}
	return (this);
}
