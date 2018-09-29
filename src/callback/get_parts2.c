/*
** EPITECH PROJECT, 2018
** get_parts2.c
** File description:
** Callback structure getter functions part.2
*/

#include "callback.h"

callback_t	*callback_set_rtype(callback_t *this, api_rtype_t type)
{
	this->rtype = type;
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
