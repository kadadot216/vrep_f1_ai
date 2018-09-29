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

int	n4s_track_cleared(callback_t *c, command_t *siminfo);
command_t	*get_simtab(void);
int	n4s_track_cleared(callback_t *c, command_t *siminfo);
void	simulation_begin(callback_t *cb, callback_col_t *col,
command_t *simulation);
void	simulation_init_vehicle(vehicle_t *this, callback_t *cb);
void	simulation_stop_vehicle(vehicle_t *this, callback_t *cb);
void	simulation_stop(callback_t *cb, command_t *simulation);
void	simulation_destroy_assets(command_t *sim, callback_t *cb);

#endif /* __SIMULATION_H__ */
