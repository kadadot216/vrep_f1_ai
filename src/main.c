/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Bootstrap
*/

#include <unistd.h>
#include <stdio.h>

#include "vehicle.h"

#include "need4stek.h"
#include "callback.h"
#include "command.h"
#include "my.h"

int	n4s_track_cleared(callback_t *c)
{
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}

int	main(int ac, char **av)
{
	char	*line = NULL;
	size_t	n = 0;
	callback_col_t	collection = callback_col_new();
	command_t	*simtab = get_simtab();
	callback_t	c = callback_new();
	vehicle_t	vehicle = vehicle_new();

	(void)ac;
	(void)av;
	callback_link_ref(&c, &collection);
	command_send(&simtab[START_SIMULATION]);
	getline(&line, &n, stdin);
	callback_get_parts(&c, line);
	callback_print_all(&c);
	sleep(2);
	vehicle_set_speed(&vehicle, 0.5);
	vehicle_update_actions(&vehicle);
	command_send(&vehicle.action[CAR_FORWARD]);
	getline(&line, &n, stdin);
	callback_get_parts(&c, line);
	//callback_print_all(&c);
	while (!n4s_track_cleared(&c)) {
		vehicle_getinfos(&vehicle, &collection);
		usleep(100);
		command_send(&simtab[GET_INFO_SIMTIME]);
		usleep(100);
		getline(&line, &n, stdin);
		callback_get_parts(&c, line);
		//callback_print_all(&c);
		usleep(200);
	}
	callback_print_all(&c);
	free(line);
	simtab = ctab_destroy(simtab, SIM_ACTIONS_SIZE);
	vehicle_destroy(&vehicle);
	callback_unset(&c);
	callback_col_free(&collection);
	sleep(2);
	return (0);
}
