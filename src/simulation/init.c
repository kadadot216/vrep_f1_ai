#include "simulation.h"

command_t	*sim_init_actions(void)
{
	int	index = 0;
	command_t	*simtab = NULL;
	command_t	data[SIM_ACTIONS_SIZE] = {
		cmd_entry(START_SIMULATION, C_START_SIMULATION, V_NONE, 1),
		cmd_entry(STOP_SIMULATION, C_STOP_SIMULATION, V_NONE, 1),
		cmd_entry(CYCLE_WAIT, C_CYCLE_WAIT, V_INT, 3),
		cmd_entry(GET_INFO_SIMTIME, C_GET_INFO_SIMTIME, V_NONE, 4)
	};
	simtab = malloc(sizeof(command_t) * SIM_ACTIONS_SIZE);
	while (index < SIM_ACTIONS_SIZE) {
		simtab[index] = data[index];
		index++;
	}
	return (simtab);
}

sim_t	*sim_destroy(sim_t *this)
{
	this->actions = command_table_destroy(this->actions, SIM_ACTIONS_SIZE);
	this->actions = NULL;
	this->status = SIM_NIL;
	this->secs = 0.0l;
	this->ns = 0.0l;
	this->track_cleared = 0;
	return (this);
}

sim_t	sim_init(void)
{
	sim_t	new;

	new.actions = sim_init_actions();
	new.status = SIM_NIL;
	new.secs = 0.0l;
	new.ns = 0.0l;
	new.track_cleared = 0;
	return (new);
}
