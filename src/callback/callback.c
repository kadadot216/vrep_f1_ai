/*
** EPITECH PROJECT, 2018
** addinfo.c
** File description:
** Addinfo creation
*/

#include <stdio.h> //d

#include "my.h"
#include "callback.h"
#include "need4stek.h"

callback_t	*callback_reset(callback_t *this)
{
	this->code = 0;
	this->status = 0;
	this->code_str = NULL;
	this->addinfo = NULL;
	this->rtype = RES_SIMTIME;
	rvals_reset(this);
	return (this);
}

callback_t	*callback_unset(callback_t *this)
{
	this = callback_reset(this);
	this->ref = NULL;
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
	this = callback_get_rvals(this, head);
	head = str_go_after_rvals(head, this);
	this = callback_get_addinfo(this, head);
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

	callback_unset(&new);
	return (new);
}
