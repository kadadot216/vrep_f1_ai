/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print function for callback
*/

#include <stdio.h>
#include "my.h"
#include "need4stek.h"

void	callback_print_all(callback_t *this)
{
	printf("callback: {\n"
		"\t\"code\": %u,\n"
		"\t\"status\": %u,\n"
		"\t\"code_str\": \"%s\",\n"
		"\t\"addinfo\": \"%s\"\n"
		"}\n", this->code, this->status,
		this->code_str,
		this->addinfo);
}
