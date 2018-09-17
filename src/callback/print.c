/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print function for callback
*/

#include <stdio.h>
#include "my.h"
#include "need4stek.h"

void	callback_print_rvals(callback_t *this)
{
	int	i = 0;

	printf("\t\"rvals\": ");
	if (this->rtype == RES_LIDAR) {
		while (i < LRES_SIZE) {
			printf((i == LRES_SIZE-1) ? "%f\n" : "%f:",
			this->rvals.lidar[i]);
			i++;
		}
	} else if (this->rtype == RES_FEEDBACK) {
		printf("[%f]\n", this->rvals.fbk);
	} else if (this->rtype == RES_SIMTIME) {
		printf("[%ld]s; [%ld]ns\n", this->rvals.stime[SIMTIME_S],
		this->rvals.stime[SIMTIME_NS]);
	}
}

void	callback_print_all(callback_t *this)
{
	printf("callback: {\n"
	"\t\"code\": %u,\n"
	"\t\"status\": %u,\n"
	"\t\"code_str\": \"%s\",\n"
	"\t\"addinfo\": \"%s\"\n"
	"}\n", this->code, this->status,
	this->code_str, this->addinfo);
	callback_print_rvals(this);
}
