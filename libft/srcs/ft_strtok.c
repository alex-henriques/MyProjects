/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:12:08 by alehenri          #+#    #+#             */
/*   Updated: 2025/07/15 14:12:25 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_delimiter(char c, const char *delimiter)
{
	while (*delimiter)
	{
		if (c == *delimiter)
			return (1);
		delimiter++;
	}
	return (0);
}

static char	*ft_skip_del_get_tok(char **saveptr, const char *delimiter)
{
	char	*start;

	while (**saveptr && ft_is_delimiter(**saveptr, delimiter))
		(*saveptr)++;
	if (!**saveptr)
	{
		*saveptr = NULL;
		return (NULL);
	}
	start = *saveptr;
	while (**saveptr && !ft_is_delimiter(**saveptr, delimiter))
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = '\0';
		(*saveptr)++;
	}
	else
		*saveptr = NULL;
	return (start);
}

char	*ft_strtok(char *str, const char *delimiter, char **saveptr)
{
	if (!delimiter || !saveptr)
		return (NULL);
	if (str)
		*saveptr = str;
	else if (!*saveptr)
		return (NULL);
	return (ft_skip_del_get_tok(saveptr, delimiter));
}

/*char	*ft_strtok(char *str, const char *delimiter, char **saveptr)
{
	char	*start;

	if (!delimiter || !saveptr)
		return (NULL);
	if (str)
		*saveptr = str;
	else if (!*saveptr)
		return (NULL);
	while (**saveptr && ft_is_delimiter(**saveptr, delimiter))
		(*saveptr)++;
	if (!**saveptr)
	{
		*saveptr = NULL;
		return (NULL);
	}
	satrt = *saveptr;
	while (**saveptr && !ft_is_delimiter(**saveptr, delimiter))
		(*saveptr)++;
	if (**saveptr)
	{
		**saveptr = '\0';
		(*saveptr)++;
	}
	else
		*saveptr = NULL;
	return (start);
}*/
