#include "push_swap.h"
static char	*spliter(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **f_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(f_str[i]);
		i++;
	}
	free(f_str);
}

static char	**fill_split(char const *s, char c, char **f_str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] != c)
			i++;
		f_str[k] = spliter(s, j, i);
		if (f_str[k] == NULL)
		{
			free_split(f_str, k);
			return (NULL);
		}
		k++;
	}
	f_str[k] = NULL;
	return (f_str);
}

char	**ft_split(char const *s, char c)
{
	char	**f_str;

	if (s == NULL)
		return (NULL);
	f_str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (f_str == NULL)
		return (NULL);
	return (fill_split(s, c, f_str));
}
