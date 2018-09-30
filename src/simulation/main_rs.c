/*
** EPITECH PROJECT, 2018
** main_rs.c
** File description:
** Simulation main routines
*/

#include <unistd.h>
#include "simulation.h"
#include "ai.h"

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

void	simulation_begin(callback_t *cb, callback_col_t *col,
sim_t *sim)
{
	cb = callback_link_ref(cb, col);
	cb = callback_set_rtype(cb, RES_NIL);
	cb = callback_getcmd(cb, &sim->actions[START_SIMULATION]);
}

void	simulation_init_vehicle(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_speed(this, SPEED_1);
	this = vehicle_update_actions(this);
	cb = callback_set_rtype(cb, RES_SIMTIME);
	cb = callback_getcmd(cb, &this->action[CAR_FORWARD]);
}

void	simulation_stop_vehicle(vehicle_t *this, callback_t *cb)
{
	while (!vehicle_too_close(this)) {
		this = vehicle_observe(this, cb);
		this = ai_update_speed(this);
		this = vehicle_update_actions(this);
		vehicle_change_speed(this, cb);
	}
}

void	simulation_stop(callback_t *cb, sim_t *sim)
{
	cb = callback_getcmd(cb, &sim->actions[STOP_SIMULATION]);
}
