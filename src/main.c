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

int	n4s_track_cleared(callback_t *c, command_t *siminfo)
{
	c = callback_set_rtype(c, RES_SIMTIME);
	callback_getcmd(c, siminfo);
	dprintf(2, "%s\n", c->addinfo);
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
	callback_getcmd(&c, &simtab[START_SIMULATION]);
	callback_set_rtype(&c, RES_SIMTIME);
	sleep(2);
	vehicle_set_speed(&vehicle, 0.5);
	vehicle_update_actions(&vehicle);
	callback_set_rtype(&c, RES_NIL);
	callback_getcmd(&c, &vehicle.action[CAR_FORWARD]);
	while (!n4s_track_cleared(&c, &simtab[GET_INFO_SIMTIME])) {
		vehicle_observe(&vehicle, &c);
		print_vehicle_infos(&vehicle);	//dbg
		//callback_print_all(&c);
		usleep(20);
	}
	callback_print_all(&c);
	usleep(2000);
	callback_getcmd(&c, &simtab[STOP_SIMULATION]);
	simtab = ctab_destroy(simtab, SIM_ACTIONS_SIZE);
	vehicle_destroy(&vehicle);
	callback_unset(&c);
	callback_col_free(&collection);
	sleep(2);
	return (0);
}
