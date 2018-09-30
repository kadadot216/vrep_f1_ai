#include "simulation.h"

void	simulation_destroy_assets(sim_t *sim, callback_t *cb)
{
	sim = sim_destroy(sim);
	cb->ref = callback_col_free(cb->ref);
	cb = callback_unset(cb);
}
