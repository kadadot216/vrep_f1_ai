#include "vehicle.h"

lidar_t		*lidar_set(lidar_t *this, float *tab)
{
	this->left_side = tab[LIDAR_LSIDE];
	this->center = tab[LIDAR_CENTER];
	this->right_side = tab[LIDAR_RSIDE];
	return (this);
}
