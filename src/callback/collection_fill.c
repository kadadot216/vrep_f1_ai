#include "need4stek.h"

callback_col_t	*callback_col_fill_addinfos(callback_col_t *this)
{
	this->l_addinfo[CODE_IFCP] = my_strdup(INFO_FCP);
	this->l_addinfo[CODE_ICP] = my_strdup(INFO_CP);
	this->l_addinfo[CODE_ILAP] = my_strdup(INFO_LAP);
	this->l_addinfo[CODE_ITRACK] = my_strdup(INFO_TRACK);
	this->l_addinfo[CODE_IOK] = my_strdup(INFO_OK);
	return (this);
}

callback_col_t	*callback_col_fill_msgs(callback_col_t *this)
{
	int	i = 0;
	char	*data[SIM_LIST_SIZE] = {
		MSG_STOPPED, MSG_OK, MSG_RUNNING, MSG_ERROR, NULL,
		MSG_CP_ERR, MSG_NET_FAILURE, MSG_SERV_ERR,
		MSG_CLIENT_ERR, MSG_EOF_REACH, MSG_DONE,
		MSG_EMPTY_CMD, MSG_UNKNOWN_CMD, MSG_WRONG_ARGS,
		MSG_MANY_ARGS, MSG_PIPE_FAIL, MSG_ARGVAL_ERR,
		MSG_INFOGET_FAIL, MSG_CMD_NOT_FOUND,
		MSG_RUN_ALREADY, MSG_CYCLE_DONE,
		MSG_SENSOR_READERR, MSG_CP_REQUIRED,
		MSG_TIMER_INIT_FAIL, MSG_TIMER_GET_FAIL,
		MSG_MAPLOAD_FAIL
	};

	while (i < SIM_LIST_SIZE) {
		this->l_code_str[i] = my_strdup(data[i]);
		i++;
	}
	return (this);
}

callback_col_t	*callback_col_fill_codes(callback_col_t *this)
{
	int	i = 0;
	api_code_t	data[SIM_LIST_SIZE] = {
		SIM_STOPPED, SIM_OK, SIM_RUNNING, SIM_ERROR, -1,
		SIM_CP_ERR, SIM_NET_FAILURE, SIM_SERV_ERR,
		SIM_CLIENT_ERR, SIM_EOF_REACH, SIM_DONE,
		SIM_EMPTY_CMD, SIM_UNKNOWN_CMD, SIM_WRONG_ARGS,
		SIM_MANY_ARGS, SIM_PIPE_FAIL, SIM_ARGVAL_ERR,
		SIM_INFOGET_FAIL, SIM_CMD_NOT_FOUND,
		SIM_RUN_ALREADY, SIM_CYCLE_DONE,
		SIM_SENSOR_READERR, SIM_CP_REQUIRED,
		SIM_TIMER_INIT_FAIL, SIM_TIMER_GET_FAIL,
		SIM_MAPLOAD_FAIL
	};

	while (i < SIM_LIST_SIZE) {
		this->l_code[i] = data[i];
		i++;
	}
	return (this);
}
