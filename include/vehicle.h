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

typedef enum	e_changeflag {
	C_NONE,
	C_DIR,
	C_SPEED,
	C_BOTH
}	changeflag_t;

typedef	struct	s_vehicle {
	float	speed;
	float	direction;
	changeflag_t	change;
	dirside_t	dirside;
	lidar_t		lidar;
	command_t	*action;
	command_t	*getinfo;
}	vehicle_t;

#define	DIR_1		(0.008f)
#define	DIR_2		(0.05f)
#define	DIR_3		(0.10f)
#define	DIR_4		(0.2f)
#define	DIR_5		(0.30f)
#define	DIR_6		(0.40f)
#define	DIR_0		(0.00f)
#define	DIR_SIZE	(7)

#define	SPEED_1		(1.0f)
#define	SPEED_2		(0.8f)
#define	SPEED_3		(0.5f)
#define	SPEED_4		(0.3f)
#define	SPEED_5		(0.2f)
#define	SPEED_6		(0.1f)
#define	SPEED_0		(0.0f)
#define	SPEED_SIZE	(7)

#define	DRANGE_1	(3010.0f)
#define	DRANGE_2	(2000.0f)
#define	DRANGE_3	(1500.0f)
#define	DRANGE_4	(1000.0f)
#define	DRANGE_5	(600.0f)
#define	DRANGE_6	(400.0f)
#define	DRANGE_7	(200.0f)
#define	DRANGE_0	(0.0f)
#define	DRANGE_SIZE	(8)

int		vehicle_too_close(vehicle_t *this);
void		print_vehicle_infos(vehicle_t *this);
void		ai_update_vehicle(vehicle_t *vehicle);
void		vehicle_change_dir(vehicle_t *vehicle, callback_t *cb);
void		vehicle_change_speed(vehicle_t *vehicle, callback_t *cb);
void		vehicle_dispatch_actions(vehicle_t *vehicle, callback_t *cb);
int		is_speed_flag_set(vehicle_t *this);
int		is_both_flags_set(vehicle_t *this);
int		is_dir_flag_set(vehicle_t *this);
int		vehicle_can_change_speed(vehicle_t *this);
int		vehicle_can_change_dir(vehicle_t *this);
vehicle_t	vehicle_new(void);
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
vehicle_t	*vehicle_set_changeflag(vehicle_t *this, changeflag_t flag);
vehicle_t	*vehicle_update_actions(vehicle_t *this);
vehicle_t	*vehicle_update_lidar(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_update_speed(vehicle_t *this, callback_t *cb);
vehicle_t	*vehicle_reset_changeflag(vehicle_t *this);

#endif /* __VEHICLE_H__ */
