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
#include "command.h"
#include "my.h"

int	n4s_track_cleared(callback_t *c)
{
	return (my_strn_eq(INFO_TRACK, c->addinfo));
}

int	main(int ac, char **av)
{
	callback_col_t	collection = callback_col_new();
	command_t	*simtab = get_simtab();
	callback_t	c = callback_new();
	vehicle_t	vehicle = vehicle_new();

	(void)ac;
	(void)av;
	callback_link_ref(&c, &collection);
	command_send(&simtab[START_SIMULATION]);
	c.rtype = RES_SIMTIME;
	callback_getcmd(&c, &simtab[START_SIMULATION]);
	callback_print_all(&c);
	sleep(2);
	vehicle_set_speed(&vehicle, 0.5);
	vehicle_update_actions(&vehicle);
	callback_getcmd(&c, &vehicle.action[CAR_FORWARD]);
	callback_print_all(&c);
	while (!n4s_track_cleared(&c)) {
		vehicle_getinfos(&vehicle, &collection);
		usleep(100);
		callback_getcmd(&c, &simtab[GET_INFO_SIMTIME]);
		//callback_print_all(&c);
		usleep(200);
	}
	callback_print_all(&c);
	simtab = ctab_destroy(simtab, SIM_ACTIONS_SIZE);
	callback_unset(&c);
	callback_col_free(&collection);
	vehicle_destroy(&vehicle);
	sleep(2);
	return (0);
}
