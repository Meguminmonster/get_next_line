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
	new_save = ft_calloc(ft_strlen(save) - i, sizeof(char));
	if (!new_save)
	{
		free(save);
		return (NULL);
	}
	i++;
	while (save[i])
		new_save[n++] = save[i++];
	free(save);
	return (new_save);
}

/* Make a line including the newline character */
char	*make_line_from(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save || !*save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = save [j];
		j++;
	}
	if (save[i] == '\n')
		line[i] = '\n';
	return (line);
}

/* Read from file descriptor until newline or EOF */
char	*read_until_enter(int fd, char *save)
{
	char	*tmp;
	int		n_of_chars;

	if (!save)
		save = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars == -1)
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[n_of_chars] = '\0';
		save = ft_free_strjoin(save, tmp);
		if (!save || ft_strchr(save, '\n'))
			break ;
	}
	free(tmp);
	return (save);
}

/* Main function */
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = read_until_enter(fd, save);
	if (!save)
		return (NULL);
	line = make_line_from(save);
	save = the_rest(save);
	return (line);
}
