#include <stdio.h>
#include "vehicle.h"

void	print_lidar(lidar_t *this)
{
	dprintf(2, " %f", this->left_side);
	dprintf(2, "\t\t%f", this->center);
	dprintf(2, "\t\t%f ", this->right_side);
}

void	print_vehicle_infos(vehicle_t *this)
{
	dprintf(2, "Vehicle: {\n"
	"\tSpeed: %f\n"
	"\tDir: %f\n"
	"\tLidar: {", this->speed, this->direction);
	print_lidar(&this->lidar);
	dprintf(2, "}\n");
}
