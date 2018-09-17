/*
** EPITECH PROJECT, 2018
** callback.h
** File description:
** Header file for Callback
*/

#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include "need4stek.h"

callback_t	*callback_get_code(callback_t *this, char *line);
callback_t	*callback_get_status(callback_t *this, char *line);
callback_t	*callback_get_code_str(callback_t *this, char *line);
callback_t	*callback_get_addinfo(callback_t *this, char *line);
callback_t	*callback_get_rvals(callback_t *this, char *line);

#endif /* __CALLBACK_H__ */
