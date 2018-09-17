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
