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

void	vehicle_change_speed(vehicle_t *vehicle, callback_t *cb)
{
	if (vehicle_can_change_speed(vehicle)) {
		dprintf(2, "Noticed speed change\n");
		callback_getcmd(cb, &vehicle->action[CAR_FORWARD]);
	}
}

void	vehicle_change_dir(vehicle_t *vehicle, callback_t *cb)
{
	if (vehicle_can_change_dir(vehicle)) {
		dprintf(2, "Noticed dir change\n");
		callback_getcmd(cb, &vehicle->action[WHEELS_DIR]);
	}
}

void	vehicle_dispatch_actions(vehicle_t *vehicle, callback_t *cb)
{
	vehicle = vehicle_update_actions(vehicle);
	vehicle_change_speed(vehicle, cb);
	vehicle_change_dir(vehicle, cb);
	vehicle = vehicle_reset_changeflag(vehicle);
}

void	ai_update_vehicle(vehicle_t *vehicle)
{
	vehicle = ai_update_speed(vehicle);
	vehicle = ai_update_direction(vehicle);
}

void	simulation_run(sim_t *sim, callback_t *cb)
{
	vehicle_t	vehicle = vehicle_new();

	simulation_init_vehicle(&vehicle, cb);
	sleep(WAIT_MAIN_S);
	while (!n4s_track_cleared(cb, &vehicle.getinfo[GET_INFO_LIDAR])) {
		vehicle_observe(&vehicle, cb);
		ai_update_vehicle(&vehicle);
		vehicle_dispatch_actions(&vehicle, cb);
		usleep(WAIT_LOOP_MS);
	}
	simulation_stop_vehicle(&vehicle, cb);
	sleep(WAIT_MAIN_S);
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
