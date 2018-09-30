#include <stdlib.h>

int	*my_inew(void)
{
	int	*value = malloc(sizeof(int));

	if (!value)
		return (NULL);
	*value = 0.0;
	return (value);
}
