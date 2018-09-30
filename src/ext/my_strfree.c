#include <stdlib.h>
#include "my.h"

char	*my_strfree(char *str)
{
	int	length = my_strlen(str);

	my_memset(str, '\0', length);
	free(str);
	str = NULL;
	return (str);
}
