/*
** EPITECH PROJECT, 2018
** my_inew.c
** File description:
** Malloc an int
*/

#include <stdlib.h>

int	*my_inew(void)
{
	int	*value = malloc(sizeof(int));

	if (!value)
		return (NULL);
	*value = 0.0;
	return (value);
}
