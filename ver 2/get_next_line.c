/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:40:09 by jpedra-v          #+#    #+#             */
/*   Updated: 2025/11/28 12:51:41 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_fd(int fd, char *save);

char	*extract_line(char *save)
{
	int		i;
	char	*line;

	if (!save || !*save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*extract_rest(char *save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rest = malloc(ft_strlen(save) - i);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		rest[j++] = save[i++];
	rest[j] = '\0';
	free(save);
	return (rest);
}

static char	*read_fd(int fd, char *save)
{
	char	*buf;
	int		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!save)
		save = ft_calloc(1, 1);
	if (!save)
	{
		free(buf);
		return (NULL);
	}
	n = 1;
	while (save && !ft_strchr(save, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[n] = '\0';
		save = ft_free_strjoin(save, buf);
		if (!save)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_fd(fd, save);
	if (!save || !*save)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = extract_line(save);
	save = extract_rest(save);
	return (line);
}
