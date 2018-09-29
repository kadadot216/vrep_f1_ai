/*
** EPITECH PROJECT, 2018
** lidar.c
** File description:
** Lidar calculations related functions
*/

#include "vehicle.h"

int	lidar_sides_over_center(lidar_t *this)
{
	return ((this->center < this->left_side) ||
	(this->center < this->right_side));
}

int	lidar_lean_left(lidar_t *this)
{
	return (this->left_side > this->right_side);
}

int	lidar_lean_right(lidar_t *this)
{
	return (this->right_side > this->left_side);
}

int	lidar_in_range(float *lidar_pt, float *range_max, float *range_min)
{
	return ((*lidar_pt >= *range_min) && (*lidar_pt < *range_max));
}
