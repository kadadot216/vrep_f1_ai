#include "need4stek.h"
#include "collection.h"

callback_col_t	*callback_col_fill(callback_col_t *this)
{
	this = callback_col_fill_codes(this);
	this = callback_col_fill_msgs(this);
	this = callback_col_fill_addinfos(this);
	return (this);
}

callback_col_t	*callback_col_free(callback_col_t *this)
{
	this = callback_col_reset_codes(this);
	this = callback_col_free_msg(this);
	this = callback_col_free_addinfos(this);
	return (this);
}

callback_col_t	callback_col_new(void)
{
	callback_col_t	new = {
		.l_code = { 0 },
		.l_code_str = { NULL },
		.l_addinfo = { NULL }
	};
	callback_col_fill(&new);
	return (new);
}
