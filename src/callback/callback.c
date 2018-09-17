/*
** EPITECH PROJECT, 2018
** addinfo.c
** File description:
** Addinfo creation
*/

#include "my.h"
#include "need4stek.h"

callback_t	*callback_free_rvals(callback_t *this)
{
	int	i = 0;

	while (i < LRES_SIZE) {
		this->rvals.lidar[i] = 0.0;
		i++;
	}
	i = 0;
	this->rvals.fbk = 0.0;
	this->rvals.stime[SIMTIME_S] = 0;
	this->rvals.stime[SIMTIME_NS] = 0;
	return (this);
}

callback_t	*callback_reset(callback_t *this)
{
	this->ref = NULL;
	this->code = 0;
	this->status = 0;
	this->code_str = NULL;
	this->addinfo = NULL;
	this->cmd_type = RES_NIL;
	this = callback_free_rvals(this);
	return (this);
}

callback_t	*callback_link_ref(callback_t *this, callback_col_t *col)
{
	this->ref = col;
	return (this);
}

callback_t	callback_new(void)
{
	callback_t	new;

	callback_reset(&new);
	return (new);
}
