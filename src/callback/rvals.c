/*
** EPITECH PROJECT, 2018
** rvals.c
** File description:
** Command for rvals
*/

#include "need4stek.h"

api_rvals_t	rvals_get_lidar(callback_t *this, char *line)
{
	char	*head = line;
	int	index = 0;

	while (index < LRES_SIZE) {
		this->rvals.lidar[index] = atof(head);
		head = str_go_to_tok(head, ':');
		index++;
	}
	return (this->rvals);
}

api_rvals_t	rvals_get_feedback(callback_t *this, char *line)
{
	this->rvals.fbk = atof(line);
	return (this->rvals);
}

api_rvals_t	rvals_get_stime(callback_t *this, char *line)
{
	char	*head = line;

	head = str_go_to_tok(head, '[');
	this->rvals.stime[SIMTIME_S] = atol(head);
	head = str_go_to_tok(head, ',');
	this->rvals.stime[SIMTIME_NS] = atol(head);
	return (this->rvals);
}

char	*str_go_after_rvals(char *head, callback_t *this)
{
	int	times = 0;

	if (this->rtype == RES_LIDAR)
		times = LRES_SIZE;
	else if (this->rtype == RES_FEEDBACK || this->rtype == RES_SIMTIME)
		times = 1;
	while (times > 0) {
		head = str_go_to_tok(head, ADDINFO_SEP);
		times--;
	}
	return (head);
}

void	rvals_reset(callback_t *this)
{
	int	i = 0;

	while (i < LRES_SIZE) {
		this->rvals.lidar[i] = 0.0;
		i++;
	}
	i = 0;
	this->rvals.fbk = 0.0;
	this->rvals.stime[SIMTIME_S] = 0;
	this->rvals.stime[SIMTIME_NS] = 0;
	return;
}
