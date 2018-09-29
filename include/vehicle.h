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

#define	LIDAR_LSIDE	(0)
#define	LIDAR_CENTER	(15)
#define	LIDAR_RSIDE	(31)

typedef struct	s_lidar {
	float	left_side;
	float	center;
	float	right_side;
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

#define	STEER_1		(0.010f)
#define	STEER_2		(0.05f)
#define	STEER_3		(0.10f)
#define	STEER_4		(0.20f)
#define	STEER_5		(0.30f)
#define	STEER_6		(0.50f)
#define	STEER_0		(0.00f)
#define	STEERS		(7)

#define	SPEED_1		(1.0f)
#define	SPEED_2		(0.80f)
#define	SPEED_3		(0.60f)
#define	SPEED_4		(0.45f)
#define	SPEED_5		(0.20f)
#define	SPEED_6		(0.15f)
#define	SPEED_0		(0.0f)
#define	SPEEDS		(7)

#define	DRANGE_1	(3010.0f)
#define	DRANGE_2	(2000.0f)
#define	DRANGE_3	(1500.0f)
#define	DRANGE_4	(1100.0f)
#define	DRANGE_5	(700.0f)
#define	DRANGE_6	(500.0f)
#define	DRANGE_7	(300.0f)
#define	DRANGE_0	(0.0f)
#define	DRANGE_TC	(80.0f)
#define	DRANGE_SIZE	(8)

void		print_vehicle_infos(vehicle_t *this);
vehicle_t	*vehicle_destroy(vehicle_t *this);
vehicle_t	*vehicle_init_actions(vehicle_t *this);
vehicle_t	*vehicle_init_getinfos(vehicle_t *this);
vehicle_t	*vehicle_observe(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_reset(vehicle_t *this);
vehicle_t	*vehicle_set_direction(vehicle_t *this, float wheels);
vehicle_t	*vehicle_set_dirside(vehicle_t *this, dirside_t side);
vehicle_t	*vehicle_set_empty_lidar(vehicle_t *this);
vehicle_t	*vehicle_set_lidar(vehicle_t *this, float *lidar);
vehicle_t	*vehicle_set_speed(vehicle_t *this, float speed);
vehicle_t	*vehicle_update_actions(vehicle_t *this);
vehicle_t	*vehicle_update_lidar(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_update_speed(vehicle_t *this, callback_t *cb);
vehicle_t	vehicle_new(void);

#endif /* __VEHICLE_H__ */
