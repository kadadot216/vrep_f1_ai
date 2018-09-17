/*
** EPITECH PROJECT, 2018
** api.h
** File description:
** Header file for api values
*/

#ifndef __API_H__
#define __API_H__

#	ifndef	__API_CMD_H__
#	define	__API_CMD_H__
#define	C_START_SIMULATION	("START_SIMULATION")
#define	C_STOP_SIMULATION	("STOP_SIMULATION")
#define	C_CAR_FORWARD		("CAR_FORWARD")
#define	C_CAR_BACKWARDS		("CAR_BACKWARDS")
#define	C_WHEELS_DIR		("WHEELS_DIR")
#define	C_GET_INFO_LIDAR	("GET_INFO_LIDAR")
#define	C_GET_CURRENT_SPEED	("GET_CURRENT_SPEED")
#define	C_GET_CURRENT_WHEELS	("GET_CURRENT_WHEELS")
#define	C_CYCLE_WAIT		("CYCLE_WAIT")
#define	C_GET_CAR_SPEED_MAX	("GET_CAR_SPEED_MAX")
#define	C_GET_CAR_SPEED_MIN	("GET_CAR_SPEED_MIN")
#define	C_GET_INFO_SIMTIME	("GET_INFO_SIMTIME")

typedef enum	e_cmdname {
	START_SIMULATION,
	STOP_SIMULATION,
	CAR_FORWARD,
	CAR_BACKWARDS,
	WHEELS_DIR,
	GET_INFO_LIDAR,
	GET_CURRENT_SPEED,
	GET_CURRENT_WHEELS,
	CYCLE_WAIT,
	GET_CAR_SPEED_MAX,
	GET_CAR_SPEED_MIN,
	GET_INFO_SIMTIME,
	CMDNAME_SIZE
}	cmdname_t;
#	endif	/* __API_CMD_H__ */

#	ifndef	__API_CALLBACK_H__
#	define	__API_CALLBACK_H__
typedef	enum	e_api_status {
	KO = 0,
	OK = !KO
}	api_status_t;

typedef enum	e_api_code {
	SIM_STOPPED = 0,
	SIM_OK = 1,
	SIM_RUNNING = 2,
	SIM_ERROR = 3,
	SIM_CP_ERR = 5,
	SIM_NET_FAILURE = 6,
	SIM_SERV_ERR = 7,
	SIM_CLIENT_ERR = 8,
	SIM_EOF_REACH = 9,
	SIM_DONE = 10,
	SIM_EMPTY_CMD = 11,
	SIM_UNKNOWN_CMD = 12,
	SIM_WRONG_ARGS = 13,
	SIM_MANY_ARGS = 14,
	SIM_PIPE_FAIL = 15,
	SIM_ARGVAL_ERR = 16,
	SIM_INFOGET_FAIL = 17,
	SIM_CMD_NOT_FOUND = 18,
	SIM_RUN_ALREADY = 19,
	SIM_CYCLE_DONE = 20,
	SIM_SENSOR_READERR = 21,
	SIM_CP_REQUIRED = 22,
	SIM_TIMER_INIT_FAIL = 23,
	SIM_TIMER_GET_FAIL = 24,
	SIM_MAPLOAD_FAIL = 25,
	SIM_LIST_SIZE = 26
}	api_code_t;

typedef enum	e_api_rtype {
	RES_NIL = 0,
	RES_CALLBACK = 1,
	RES_LIDAR = 2,
	RES_FEEDBACK = 3,
	RES_SIMTIME = 4,
	API_RTYPE_SIZE
}	api_rtype_t;

#define	MSG_STOPPED		("Simulation has not been launched")
#define	MSG_OK			("No errors so far")
#define	MSG_RUNNING		("Simulation running")
#define	MSG_ERROR		("Error. No details can be provided atm")
#define	MSG_CP_ERR		("Checkpoint error detected")
#define	MSG_NET_FAILURE		("Network operation failure")
#define	MSG_SERV_ERR		("Server-side Error")
#define	MSG_CLIENT_ERR		("Client-side Error")
#define	MSG_EOF_REACH		("EOF reached")
#define	MSG_DONE		("Simulation was correctly ended")
#define	MSG_EMPTY_CMD		("Empty command")
#define	MSG_UNKNOWN_CMD		("Unkown command")
#define	MSG_WRONG_ARGS		("Wrong arguments provided."	\
				" Please refer to protocol")
#define	MSG_MANY_ARGS		("Too many args provided with the command." \
				" Please refer to protocol")
#define	MSG_PIPE_FAIL		("Pipeline failure")
#define	MSG_ARGVAL_ERR		("Unexpected command argument's value")
#define	MSG_INFOGET_FAIL	("Camera infoget failure")
#define	MSG_CMD_NOT_FOUND	("Command not found")
#define	MSG_RUN_ALREADY		("Simulation already up and running")
#define	MSG_CYCLE_DONE		("CYCLE_DONE")
#define	MSG_SENSOR_READERR	("Sensor reading failure")
#define	MSG_CP_REQUIRED		("Scene must contain at least 3 CPs")
#define	MSG_TIMER_INIT_FAIL	("Timer Init Failure")
#define	MSG_TIMER_GET_FAIL	("Timer get Failure")
#define	MSG_MAPLOAD_FAIL	("Failed to load map")

#define	INFO_FCP	("First CP Cleared")
#define	INFO_CP		("CP Cleared")
#define	INFO_LAP	("Lap Cleared")
#define	INFO_TRACK	("Track Cleared")
#define	INFO_OK		("No further info")
#	endif /* __API_CALLBACK_H__ */

#endif /* __API_H__ */
