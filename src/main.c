/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Bootstrap
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "need4stek.h"
#include "my.h"


int	main(int ac, char **av)
{
	char	*line = NULL;
	size_t	n = 0;

	(void)ac;
	(void)av;
	send_command("START_SIMULATION\n");
	getline(&line, &n, stdin);
	my_putstr_fd(2, line);
	sleep(2);
	send_command("CAR_FORWARD:0.2\n");
	getline(&line, &n, stdin);
	my_putstr_fd(2, line);
	while (n4s_track_cleared(line) == 0) {
		send_command("GET_INFO_SIMTIME\n");
		getline(&line, &n, stdin);
		my_putstr_fd(2, line);
		sleep(1);
	}
	free(line);
	my_putstr_fd(2, "Tracku finished dayo!\n");
	sleep(10);
	return (0);
}
