/*
** EPITECH PROJECT, 2018
** simulation.h
** File description:
** Header file for simulation routines
*/

#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "command.h"
#include "callback.h"
#include "vehicle.h"

typedef	enum e_simstatus {
	SIM_NIL,
	SIM_STOP,
	SIM_START
}	simstatus_t;

typedef struct	s_sim {
	command_t	*actions;
	simstatus_t	status;
	long		secs;
	long		ns;
	int		track_cleared;
}	sim_t;

void		simulation_begin(callback_t *cb, callback_col_t *col, sim_t *);
void		simulation_destroy_assets(sim_t *sim, callback_t *cb);
void		simulation_init_vehicle(vehicle_t *this, callback_t *cb);
void		simulation_stop(callback_t *cb, sim_t *sim);
void		simulation_stop_vehicle(vehicle_t *this, callback_t *cb);
command_t	*sim_init_actions(void);
sim_t		*sim_destroy(sim_t *this);
sim_t		sim_init(void);

#endif /* __SIMULATION_H__ */
