/*
** EPITECH PROJECT, 2018
** main_rs.c
** File description:
** Simulation main routines
*/

#include "simulation.h"

void	simulation_begin(callback_t *cb, callback_col_t *col,
sim_t *sim)
{
	cb = callback_link_ref(cb, col);
	cb = callback_set_rtype(cb, RES_NIL);
	cb = callback_getcmd(cb, &sim->actions[START_SIMULATION]);
}

void	simulation_init_vehicle(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_speed(this, SPEED_4);
	this = vehicle_update_actions(this);
	cb = callback_set_rtype(cb, RES_SIMTIME);
	cb = callback_getcmd(cb, &this->action[CAR_FORWARD]);
}

void	simulation_stop_vehicle(vehicle_t *this, callback_t *cb)
{
	this = vehicle_set_speed(this, SPEED_0);
	this = vehicle_update_actions(this);
	cb = callback_getcmd(cb, &this->action[CAR_FORWARD]);
}

void	simulation_stop(callback_t *cb, sim_t *sim)
{
	cb = callback_getcmd(cb, &sim->actions[STOP_SIMULATION]);
}
