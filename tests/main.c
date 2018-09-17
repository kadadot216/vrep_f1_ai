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
	char	*line = "1:OK:No errors so far:700.0:750.0:800.0:850.0:975.0"
		":1050.0:1125.0:1225.0:1375.0:1500.0:2500.0:2750.0:3000.0"
		":3010.0:3010.0:3010.0:3010.0:3010.0:3010.0:3010.0:3000.0:"
		"2750.0:2500.0:1500.0:1375.0:1225.0:1125.0:1050.0:975.0:900.0:"
		"850.0:800.0:No further info\n";
	(void)ac;
	(void)av;
	c.rtype = RES_LIDAR;
	callback_col_print_all(&collection);
	callback_link_ref(&c, &collection);
	callback_get_parts(&c, line);
	callback_print_all(&c);
	callback_reset(&c);
	callback_col_free(&collection);
	return (0);
}
