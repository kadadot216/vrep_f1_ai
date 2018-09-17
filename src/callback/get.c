/*
** EPITECH PROJECT, 2018
** callback.c
** File description:
** callback actions for addinfo structure
*/

#include "my.h"
#include "need4stek.h"

static callback_t	*callback_get_code(callback_t *this, char *line)
{
	this->code = ((api_code_t) my_getnbr(line));
	return (this);
}

static callback_t	*callback_get_status(callback_t *this, char *line)
{
	this->status = (my_strn_eq(line, "OK")) ? OK : KO;
	return (this);
}

static callback_t	*callback_get_code_str(callback_t *this, char *line)
{
	char	*code_str_ref = this->ref->l_code_str[this->code];

	if (my_strn_eq(line, code_str_ref))
		this->code_str = code_str_ref;
	return(this);
}

static callback_t	*callback_get_addinfo(callback_t *this, char *line)
{
	int	i = 0;
	char	**addinfo_ref = this->ref->l_addinfo;

	while (i < ADDINFO_PTS) {
		if (my_strn_eq(line, addinfo_ref[i])) {
			this->code_str = addinfo_ref[i];
			return (this);
		}
		i++;
	}
	return (this);
}

api_rvals_t	rvals_get_lidar(callback_t *this, char *line)
{
	this->rvals.lidar; //itoa
}

api_rvals_t	rvals_get_feedback(callback_t *this, char *line)
{
	this->rvals.fbk; //itoa

}

api_rvals_t	rvals_get_stime(callback_t *this, char *line)
{
	this->rvals.stime; //itoa

}

static callback_t	*callback_get_rtype(callback_t *this, char *line)
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

callback_t	*callback_get_parts(callback_t *this, char *line)
{
	char	*head = line;

	this = callback_get_code(this, head);
	head = str_go_to_tok(head, ADDINFO_SEP);
	this = callback_get_status(this, head);
	head = str_go_to_tok(head, ADDINFO_SEP);
	this = callback_get_code_str(this, head);
	head = str_go_to_tok(head, ADDINFO_SEP);
	this = callback_get_addinfo(this, head);
	return (this);
}
