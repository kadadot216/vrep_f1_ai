/*
** EPITECH PROJECT, 2018
** vehicle.h
** File description:
** Header file for vehicle related functions
*/

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "need4stek.h"
#include "command.h"

#define	CORNER_SIZE	(7)
#define	SIDE_SIZE	(5)
#define	CENTER_SIZE	(8)

#define	LCORNER_START	(0)
#define	LSIDE_START	(7)
#define	CENTER_START	(12)
#define	RSIDE_START	(20)
#define	RCORNER_START	(25)

typedef struct	s_lidar {
	float	left_corner;
	float	left_side;
	float	center;
	float	right_side;
	float	right_corner;
}	lidar_t;

typedef	struct	s_vehicle {
	float	speed;
	float	direction;
	lidar_t		lidar;
	command_t	*action;
	command_t	*getinfo;
}	vehicle_t;

#define	WHEEL_TICK	((2.0f) / (LRES_SIZE))

vehicle_t	*vehicle_getinfos(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_update_speed(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_update_direction(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_update_lidar(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_set_speed(vehicle_t *this, float speed);
vehicle_t	*vehicle_set_direction(vehicle_t *this, float wheels);
vehicle_t	*vehicle_set_lidar(vehicle_t *this, float *lidar);
vehicle_t	*vehicle_set_empty_lidar(vehicle_t *this);
vehicle_t	*vehicle_reset(vehicle_t *this);
vehicle_t	*vehicle_init_actions(vehicle_t *this);
vehicle_t	*vehicle_init_getinfos(vehicle_t *this);
vehicle_t	*vehicle_update_actions(vehicle_t *this);
vehicle_t	*vehicle_destroy(vehicle_t *this);
vehicle_t	*vehicle_observe(vehicle_t *this, callback_t *cb);
vehicle_t	vehicle_new(void);
void		print_vehicle_infos(vehicle_t *this);	//dbg

#endif /* __VEHICLE_H__ */
