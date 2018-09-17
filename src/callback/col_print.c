/*
** EPITECH PROJECT, 2018
** col_print.c
** File description:
** Print related functions for callback
*/

#include <stdio.h>
#include "need4stek.h"

void	callback_col_print_codes(callback_col_t	*this)
{
	int	i = 0;

	while (i < SIM_LIST_SIZE) {
		if (this->l_code_str[i] != NULL) {
			printf("\t%u \t--> %s\n", this->l_code[i],
			this->l_code_str[i]);
		}
		i++;
	}
}

void	callback_col_print_addinfos(callback_col_t *this)
{
	int	i = 0;

	while (i < ADDINFO_PTS) {
		printf("\t(%u): %s\n", i, this->l_addinfo[i]);
		i++;
	}
}

void	callback_col_print_all(callback_col_t *this)
{
	printf("Collection codes:\n");
	callback_col_print_codes(this);
	printf("Collection addinfos:\n");
	callback_col_print_addinfos(this);
}
