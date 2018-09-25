/*
** EPITECH PROJECT, 2018
** collection.h
** File description:
** Header file for collection operations
*/

#ifndef __COLLECTION_H__
#define __COLLECTION_H__

#include "need4stek.h"

void	callback_col_print_addinfos(callback_col_t *this);
void	callback_col_print_all(callback_col_t *this);
void	callback_col_print_codes(callback_col_t	*this);
void	callback_print_all(callback_t *this);
callback_col_t	*callback_col_fill(callback_col_t *this);
callback_col_t	*callback_col_fill_addinfos(callback_col_t *this);
callback_col_t	*callback_col_fill_codes(callback_col_t *this);
callback_col_t	*callback_col_fill_msgs(callback_col_t *this);
callback_col_t	*callback_col_free(callback_col_t *this);
callback_col_t	*callback_col_free_addinfos(callback_col_t *this);
callback_col_t	*callback_col_free_msg(callback_col_t *this);
callback_col_t	*callback_col_free_rtypes(callback_col_t *this);
callback_col_t	*callback_col_reset_codes(callback_col_t *this);
callback_col_t	callback_col_new(void);

#endif /* __COLLECTION_H__ */
