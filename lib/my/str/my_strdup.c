#include <stdlib.h>
#include "my.h"

char	*my_strdup(char const *src)
{
	int	i = 0;
	int	slen = 0;
	char	*copy;

	if (src == NULL)
		return (NULL);
	slen = my_strlen(src);
	copy = malloc(sizeof(*src) * (slen + 1));
	my_memset(copy, '\0', slen);
	while (src[i] != '\0') {
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
