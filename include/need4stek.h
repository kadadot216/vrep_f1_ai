/*
** EPITECH PROJECT, 2018
** need4stek.h
** File description:
** Header file for Need4Stek structures
*/

#ifndef __NEED4STEK_H__
#define __NEED4STEK_H__

#include <stdlib.h>
#include "my.h"
#include "api.h"

#define	ADDINFO_PTS	(5)
#define	CODE_IFCP	(0)
#define	CODE_ICP	(1)
#define	CODE_ILAP	(2)
#define	CODE_ITRACK	(3)
#define	CODE_IOK	(4)
#define	ADDINFO_SEP	(':')

typedef struct	s_callback_col {
	api_code_t	l_code[SIM_LIST_SIZE];
	char		*l_code_str[SIM_LIST_SIZE];
	char		*l_addinfo[ADDINFO_PTS];
}	callback_col_t;

callback_col_t	*callback_col_fill(callback_col_t *this);

#define RI_CALLBACK 	(0)
#define RI_LIDAR 	(1)
#define RI_FEEDBACK 	(2)
#define RI_SIMTIME 	(3)

#define	LRES_SIZE	(32)
#define	STIME_SIZE	(2)
#define	SIMTIME_S	(0)
#define	SIMTIME_NS	(1)

typedef	union	u_api_rvals {
	float	lidar[LRES_SIZE];
	float	fbk;
	long	stime[STIME_SIZE];
}		api_rvals_t;

typedef struct	s_callback {
	callback_col_t	*ref;
	api_code_t	code;
	api_status_t	status;
	api_rtype_t	rtype;
	api_rvals_t	rvals;
	char		*code_str;
	char		*addinfo;
}	callback_t;

typedef	struct	s_command {
	cmdname_t	name;
	char		*prefix;
	float		*value;
	api_rtype_t	rtype;
}		command_t;

void	callback_col_print_addinfos(callback_col_t *this);
void	callback_col_print_all(callback_col_t *this);
void	callback_col_print_codes(callback_col_t	*this);
api_rvals_t	rvals_get_lidar(callback_t *this, char *line);
api_rvals_t	rvals_get_feedback(callback_t *this, char *line);
api_rvals_t	rvals_get_stime(callback_t *this, char *line);
callback_col_t	*callback_col_fill(callback_col_t *this);
callback_col_t	*callback_col_free(callback_col_t *this);
callback_col_t	callback_col_new(void);

void	callback_print_all(callback_t *this);
callback_t	*callback_link_ref(callback_t *this, callback_col_t *col);
callback_t	*callback_get_parts(callback_t *this, char *line);
callback_t	*callback_reset(callback_t *this);
callback_t	callback_new(void);

#endif /* __NEED4STEK_H__ */
