/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:23:09 by dlopez-s          #+#    #+#             */
/*   Updated: 2022/11/11 13:10:17 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free (stash);
	return (str);
}

static char	*ft_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_readandstash(int fd, char *stash)
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_readandstash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	stash[fd] = ft_stash(stash[fd]);
	return (line);
}

/* int main()
{
	get_next_line(-4);
	return (0);
} */