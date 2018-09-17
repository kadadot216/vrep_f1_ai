/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Bootstrap
*/

#include <unistd.h>
#include <stdio.h>
#include "need4stek.h"
#include "command.h"
#include "my.h"

int	n4s_track_cleared(callback_t *c)
{
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}

int	main(int ac, char **av)
{
	char	*line = NULL;
	float	*value = malloc(sizeof(float));
	size_t	n = 0;
	callback_col_t	collection = callback_col_new();
	callback_t	c = callback_new();

	(void)ac;
	(void)av;
	*value = 1.0f;
	callback_link_ref(&c, &collection);
	command_psend("START_SIMULATION", NULL);
	getline(&line, &n, stdin);
	callback_get_parts(&c, line);
	callback_print_all(&c);
	sleep(2);
	command_psend("CAR_FORWARD", value);
	getline(&line, &n, stdin);
	callback_get_parts(&c, line);
	callback_print_all(&c);
	my_putstr_fd(2, line);
	while (!n4s_track_cleared(&c)) {
		command_psend("GET_INFO_SIMTIME", NULL);
		getline(&line, &n, stdin);
		callback_get_parts(&c, line);
		callback_print_all(&c);
		usleep(500);
	}
	callback_print_all(&c);
	callback_unset(&c);
	callback_col_free(&collection);
	free(line);
	sleep(2);
	return (0);

}
