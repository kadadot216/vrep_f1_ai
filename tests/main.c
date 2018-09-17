/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for debugging purposes
*/

#include "need4stek.h"

int	main(int ac, char **av)
{
	callback_col_t	collection = callback_col_new();
	callback_t	c = callback_new();
	char	*line = "1:OK:No errors so far:[14s,111941936ns]:Track Cleared: [-1][13s 211248516ns]\n";

	(void)ac;
	(void)av;
	c.rtype = RES_SIMTIME;
	callback_col_print_all(&collection);
	callback_link_ref(&c, &collection);
	callback_get_parts(&c, line);
	callback_print_all(&c);
	callback_reset(&c);
	callback_col_free(&collection);
	return (0);
}
