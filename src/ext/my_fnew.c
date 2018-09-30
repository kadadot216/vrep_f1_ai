#include <stdlib.h>

float	*my_fnew(void)
{
	float	*value = malloc(sizeof(float));

	if (!value)
		return (NULL);
	*value = 0.0;
	return (value);
}
