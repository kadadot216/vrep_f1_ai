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

#include "simulation.h"

void	simulation_run(command_t *sim, callback_t *cb)
{
	vehicle_t	vehicle = vehicle_new();

	simulation_init_vehicle(&vehicle, cb);
	sleep(2);
	while (!n4s_track_cleared(cb, &sim[GET_INFO_SIMTIME])) {
		vehicle_observe(&vehicle, cb);
		//print_vehicle_infos(&vehicle);	//dbg
		ai_update_vehicle(&vehicle);
		vehicle_update_actions(&vehicle);
		callback_getcmd(cb, &vehicle.action[WHEELS_DIR]);
		callback_getcmd(cb, &vehicle.action[CAR_FORWARD]);
		usleep(20);
	}
	simulation_stop_vehicle(&vehicle, cb);
	sleep(2);
	simulation_stop(cb, sim);
	vehicle_destroy(&vehicle);
}

int	main(int ac, char **av)
{
	callback_col_t	collection = callback_col_new();
	command_t	*simtab = get_simtab();
	callback_t	c = callback_new();

	(void)ac;
	(void)av;
	simulation_begin(&c, &collection, simtab);
	simulation_run(simtab, &c);
	simulation_destroy_assets(simtab, &c);
	return (0);
}
