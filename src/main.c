/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Bootstrap
*/

#include <unistd.h>
#include <stdio.h>

#include"ai.h"
#include "need4stek.h"
#include "callback.h"
#include "command.h"
#include "my.h"

int	main(int ac, char **av)
{
	callback_col_t	collection = callback_col_new();
	command_t	*simtab = get_simtab();
	callback_t	c = callback_new();
	vehicle_t	vehicle = vehicle_new();

	(void)ac;
	(void)av;
	callback_link_ref(&c, &collection);
	callback_set_rtype(&c, RES_NIL);
	callback_getcmd(&c, &simtab[START_SIMULATION]);
	sleep(2);
	vehicle_set_speed(&vehicle, SPEED_4);
	vehicle_update_actions(&vehicle);
	callback_set_rtype(&c, RES_SIMTIME);
	callback_getcmd(&c, &vehicle.action[CAR_FORWARD]);
	while (!n4s_track_cleared(&c, &simtab[GET_INFO_SIMTIME])) {
		vehicle_observe(&vehicle, &c);
		print_vehicle_infos(&vehicle);	//dbg
		ai_update_vehicle(&vehicle);
		vehicle_update_actions(&vehicle);
		callback_getcmd(&c, &vehicle.action[WHEELS_DIR]);
		callback_getcmd(&c, &vehicle.action[CAR_FORWARD]);
		usleep(20);
	}
	vehicle_set_speed(&vehicle, SPEED_0);
	vehicle_update_actions(&vehicle);
	callback_getcmd(&c, &vehicle.action[CAR_FORWARD]);
	sleep(3);
	callback_getcmd(&c, &simtab[STOP_SIMULATION]);
	simtab = command_table_destroy(simtab, SIM_ACTIONS_SIZE);
	vehicle_destroy(&vehicle);
	callback_unset(&c);
	callback_col_free(&collection);
	return (0);
}
