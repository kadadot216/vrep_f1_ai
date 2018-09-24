/*
** EPITECH PROJECT, 2018
** actions.c
** File description:
** Vehicle actions tab 
*/

#include <stdlib.h>

#include <stdio.h>
#include "vehicle.h"
#include "callback.h"
#include "command.h"

callback_t	*callback_get(callback_t *this, command_t *command)
{
	char		*raw_res = NULL;
	size_t		n = 0;
	
	command_send(command);
	getline(&raw_res, &n, stdin);
	dprintf(2, "%d", this->rtype);
	callback_get_parts(this, raw_res);
	callback_print_all(this);
	return (this);
}

void	print_lidar(float lidar[LRES_SIZE])
{
	int	i = 0;

	while (i < LRES_SIZE) {
		dprintf(2, (i < (LRES_SIZE - 1)) ? "\t\t%f, " :
		"\t\t%f\n\t}\n", lidar[i]);
		i++;
	}
}

void	print_vehicle_infos(vehicle_t *this)
{
	dprintf(2, "Vehicle: {\n"
		"\tSpeed: %f\n"
		"\tDir: %f\n"
		"\tLidar: {", this->speed, this->direction);
	print_lidar(this->lidar);
	dprintf(2, "}\n");
}

vehicle_t	*vehicle_getinfos(vehicle_t *this, callback_col_t *col)
{
	callback_t	cb = callback_new();

	callback_link_ref(&cb, col);
	dprintf(2, "lidar:\n");	//dbg
	// Faire qqchose pour mapper le lidar à partir de
	// du message de collection
	// Prototype (callback_t *, callback_col_t, line)
	cb.rtype = RES_LIDAR;
	callback_get(&cb, &this->getinfo[GET_INFO_LIDAR]);
	this = vehicle_update_lidar(this, &cb);
	//dprintf(2, "speed:\n");	//dbg
	cb.rtype = RES_FEEDBACK;
	callback_get(&cb, &this->getinfo[GET_CURRENT_SPEED]);
	this = vehicle_update_speed(this, &cb);
	//dprintf(2, "direction:\n");	//dbg
	cb.rtype = RES_FEEDBACK;
	callback_get(&cb, &this->getinfo[GET_CURRENT_WHEELS]);
	this = vehicle_update_direction(this, &cb);
	//print_vehicle_infos(this);	//dbg
	callback_unset(&cb);
	return (this);
}
