/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Bootstrap
*/

#include <stdio.h>

#include"ai.h"
#include "need4stek.h"
#include "callback.h"
#include "command.h"
#include "my.h"

#include "simulation.h"

int	main(int ac, char **av)
{
	callback_col_t	collection = callback_col_new();
	sim_t		sim = sim_init();
	callback_t	c = callback_new();

	(void)ac;
	(void)av;
	simulation_begin(&c, &collection, &sim);
	simulation_run(&sim, &c);
	simulation_destroy_assets(&sim, &c);
	return (0);
}
