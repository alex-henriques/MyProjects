/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:56:42 by alehenri          #+#    #+#             */
/*   Updated: 2024/12/10 10:11:40 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*ft_setline(char *bufferline)
{
	char	*leftovers;
	ssize_t	i;

	i = 0;
	while (bufferline[i] != '\n' && bufferline[i] != '\0')
		i++;
	if (bufferline[i] == 0 || bufferline[1] == 0)
		return (NULL);
	leftovers = ft_substr(bufferline, i + 1, ft_strlen(bufferline) - 1);
	if (*leftovers == 0)
	{
		free(leftovers);
		leftovers = NULL;
	}
	bufferline[i + 1] = 0;
	return (leftovers);
}

static char	*ft_fillbuffer(int fd, char *leftovers, char *buffer)
{
	ssize_t	bufferread;
	char	*temp;

	bufferread = 1;
	while (bufferread > 0)
	{
		bufferread = read(fd, buffer, BUFFER_SIZE);
		if (bufferread == -1)
		{
			free(leftovers);
			return (NULL);
		}
		else if (bufferread == 0)
			break ;
		buffer[bufferread] = 0;
		if (!leftovers)
			leftovers = ft_strdup("");
		temp = leftovers;
		leftovers = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
	{
		free(leftovers[fd]);
		free(buffer);
		return (0);
	}
	line = ft_fillbuffer(fd, leftovers[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftovers[fd] = ft_setline(line);
	return (line);
}
