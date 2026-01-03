/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:40:26 by alehenri          #+#    #+#             */
/*   Updated: 2024/11/04 18:52:27 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*str != '\0')
	{
		if (*str != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*str == c)
		{
			word = 0;
		}
		str++;
	}
	return (count);
}

static char	*extractword(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	*freememory(char **string, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (0);
}

static void	variables(size_t *i, int *j, int *word)
{
	*i = 0;
	*j = 0;
	*word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		j;
	int		word;

	variables(&i, &j, &word);
	result = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!result)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word < 0)
			word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word >= 0)
		{
			result[j] = extractword(s, word, i);
			if (!(result[j]))
				return (freememory(result, j));
			word = -1;
			j++;
		}
		i++;
	}
	return (result);
}
