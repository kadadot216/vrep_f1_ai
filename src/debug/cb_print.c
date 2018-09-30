/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print function for callback
*/

#include <stdio.h>
#include "my.h"
#include "need4stek.h"

void	rvals_print_res_lidar(callback_t *this)
{
	int	i = 0;

	while (i < LRES_SIZE) {
		fprintf(stderr, (i == LRES_SIZE-1) ? "%f\n" : "%f, ",
		this->rvals.lidar[i]);
		i++;
	}
}

void	callback_print_rvals(callback_t *this)
{
	fprintf(stderr, "\t\"rvals \": \n\t");
	if (this->rtype == RES_LIDAR) {
		rvals_print_res_lidar(this);
	} else if (this->rtype == RES_FEEDBACK) {
		fprintf(stderr, "[%f]\n", this->rvals.fbk);
	} else if (this->rtype == RES_SIMTIME) {
		fprintf(stderr, "[%ld]s; [%ld]ns\n",
		this->rvals.stime[SIMTIME_S],
		this->rvals.stime[SIMTIME_NS]);
	}
}

void	callback_print_all(callback_t *this)
{
	fprintf(stderr, "callback: {\n"
	"\t\"code\": %u,\n"
	"\t\"status\": %u,\n"
	"\t\"code_str\": \"%s\",\n"
	"\t\"addinfo\": \"%s\"\n", this->code, this->status,
	this->code_str, this->addinfo);
	callback_print_rvals(this);
	fprintf(stderr, "}\n");
}
