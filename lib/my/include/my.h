/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header file for my
*/

#ifndef __MY_H__
#define __MY_H__

#	ifndef	__STR_H__
#	define __MY_H__
int	my_strncmp(char const *s1, char const *s2, int n);
int	my_strlen(char const *str);
char	*my_strdup(char const *src);
void	my_memset(char *str, char c, unsigned int size);
#	endif /* __MY_H__ */
int	my_putstr_fd(int fd, const char *str);
char	*str_go_to_tok(char *str, char tok);
char	*my_strfree(char *str);
int	my_getnbr(char const *str);
int	my_strn_eq(char const *cmped, char const *cmper);
float	*my_fnew(void);

#endif /* __MY_H__ */
