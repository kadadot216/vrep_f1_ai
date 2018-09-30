char	*str_go_to_tok(char *str, char tok)
{
	int	head = 0;
	char	*start = str;

	while (str[head] != '\0' && str[head] != tok)
		head++;
	if (str[head] == '\0')
		return (start);
	head++;
	return (&str[head]);
}
