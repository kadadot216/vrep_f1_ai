/*
** EPITECH PROJECT, 2018
** lidar.h
** File description:
** Header file for Lidar functions
*/

#ifndef __LIDAR_H__
#define __LIDAR_H__

#include "vehicle.h"

int	lidar_sides_over_center(lidar_t *this);
int	lidar_lean_left(lidar_t *this);
int	lidar_lean_right(lidar_t *this);
int	lidar_in_range(float *lidar_pt, float *range_max, float *range_min);
lidar_t	*lidar_set(lidar_t *this, float *tab);

#endif /* __LIDAR_H__ */
