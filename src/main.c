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

void	vehicle_dispatch_actions(vehicle_t *vehicle, callback_t *cb)
{
	vehicle_update_actions(vehicle);
	if (vehicle_can_change_speed(vehicle)) {
		dprintf(2, "Noticed speed change\n");
		callback_getcmd(cb, &vehicle->action[CAR_FORWARD]);
	}
	if (vehicle_can_change_dir(vehicle)) {
		dprintf(2, "Noticed dir change\n");
		callback_getcmd(cb, &vehicle->action[WHEELS_DIR]);
	}
}

void	ai_update_vehicle(vehicle_t *vehicle)
{
	ai_update_speed(vehicle);
	ai_update_direction(vehicle);
}

void	simulation_run(sim_t *sim, callback_t *cb)
{
	vehicle_t	vehicle = vehicle_new();

	simulation_init_vehicle(&vehicle, cb);
	sleep(2);
	while (!n4s_track_cleared(cb, &vehicle.getinfo[GET_INFO_LIDAR])) {
		vehicle_observe(&vehicle, cb);
		//print_vehicle_infos(&vehicle);	//dbg
		ai_update_vehicle(&vehicle);
		vehicle_dispatch_actions(&vehicle, cb);
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
	sim_t		sim = sim_init();
	callback_t	c = callback_new();

	(void)ac;
	(void)av;
	simulation_begin(&c, &collection, &sim);
	simulation_run(&sim, &c);
	simulation_destroy_assets(&sim, &c);
	return (0);
}
