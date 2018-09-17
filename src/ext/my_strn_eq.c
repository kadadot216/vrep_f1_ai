/*
** EPITECH PROJECT, 2018
** my_strneq.c
** File description:
** Compare a part of string with other string
*/

#include "my.h"

int	my_strn_eq(char const *cmped, char const *cmper)
{
	return (!(my_strncmp(cmper, cmped, my_strlen(cmper))));
}
