#include "need4stek.h"

callback_col_t	*callback_col_reset_codes(callback_col_t *this)
{
	int	i = 0;

	while (i < SIM_LIST_SIZE) {
		this->l_code[i] = 0;
		i++;
	}
	return (this);
}

callback_col_t	*callback_col_free_msg(callback_col_t *this)
{
	int	i = 0;
	char	**that = this->l_code_str;

	while (i < SIM_LIST_SIZE) {
		if (that[i] != NULL) {
			that[i] = my_strfree(that[i]);
		}
		i++;
	}
	return (this);
}

callback_col_t	*callback_col_free_addinfos(callback_col_t *this)
{
	char	**that = this->l_addinfo;

	that[CODE_IFCP] = my_strfree(that[CODE_IFCP]);
	that[CODE_ICP] = my_strfree(that[CODE_ICP]);
	that[CODE_ILAP] = my_strfree(that[CODE_ILAP]);
	that[CODE_ITRACK] = my_strfree(that[CODE_ITRACK]);
	that[CODE_IOK] = my_strfree(that[CODE_IOK]);
	return (this);
}
