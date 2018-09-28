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

#define	CORNER_SIZE	(5)
#define	SIDE_SIZE	(5)
#define	CENTER_SIZE	(12)

#define	LSIDE_START	(4)
#define	CENTER_START	(16)
#define	RSIDE_START	(27)

#define	LIDAR_ANGLES	(3)

typedef struct	s_lidar {
	float	left_corner;
	float	left_side;
	float	center;
	float	right_side;
	float	right_corner;
}	lidar_t;

typedef enum	e_dirside {
	DS_LEFT,
	DS_CENTER,
	DS_RIGHT
}	dirside_t;

typedef	struct	s_vehicle {
	float	speed;
	float	direction;
	dirside_t	dirside;
	lidar_t		lidar;
	command_t	*action;
	command_t	*getinfo;
}	vehicle_t;

#define	STEER_1		(0.008f)
#define	STEER_2		(0.05f)
#define	STEER_3		(0.10f)
#define	STEER_4		(0.2f)
#define	STEER_5		(0.30f)
#define	STEER_6		(0.40f)
#define	STEER_7		(0.00f)
#define	STEERS		(7)

#define	SPEED_1		(1.0f)
#define	SPEED_2		(0.8f)
#define	SPEED_3		(0.5f)
#define	SPEED_4		(0.3f)
#define	SPEED_5		(0.2f)
#define	SPEED_6		(0.1f)
#define	SPEED_7		(0.0f)
#define	SPEEDS		(7)

#define	DRANGE_0	(3010.0f)
#define	DRANGE_1	(2000.0f)
#define	DRANGE_2	(1500.0f)
#define	DRANGE_3	(1000.0f)
#define	DRANGE_4	(600.0f)
#define	DRANGE_5	(400.0f)
#define	DRANGE_6	(200.0f)
#define	DRANGE_7	(0.0f)
#define	DRANGE_SIZE	(8)

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

vehicle_t	*vehicle_update_params(vehicle_t *this); //test

#endif /* __VEHICLE_H__ */
