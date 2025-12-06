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

/* Extract the part of 'save' after the first newline */
char	*the_rest(char *save)
{
	char	*new_save;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	new_save = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	if (!new_save)
	{
		free(save);
		return (NULL);
	}
	n = 0;
	while (save[i])
		new_save[n++] = save[i++];
	new_save[n] = '\0';
	free(save);
	return (new_save);
}

/* Make a line including the newline character */
char	*make_line_from(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save || save[0] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + (save[i] == '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (save[i] && save[i] != '\n')
	{
		line[i] = save [i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* Read from file descriptor until newline or EOF */
char	*read_until_enter(int fd, char *save)
{
	char	*buffer;
	int		bytes;

	if (!save)
		save = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (save);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[bytes] = '\0';
		save = ft_free_strjoin(save, buffer);
		if (!save || ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

/* Main function */
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_until_enter(fd, save);
	if (!save)
		return (NULL);
	line = make_line_from(save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = the_rest(save);
	return (line);
}
