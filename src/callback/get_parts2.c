#include "callback.h"

callback_t	*callback_set_rtype(callback_t *this, api_rtype_t type)
{
	this->rtype = type;
	return (this);
}

callback_t	*callback_get_rvals(callback_t *this, char *line)
{
	if (this->rtype == RES_LIDAR) {
		this->rvals = rvals_get_lidar(this, line);
		return (this);
	} else if (this->rtype == RES_FEEDBACK) {
		this->rvals = rvals_get_feedback(this, line);
		return (this);
	}
	this->rvals = rvals_get_stime(this, line);
	return (this);
}
