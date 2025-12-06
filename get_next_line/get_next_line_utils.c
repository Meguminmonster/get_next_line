/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:41:16 by jpedra-v          #+#    #+#             */
/*   Updated: 2025/11/28 16:43:23 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* strlen */
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/* strchr */
char	*ft_strchr(char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == (char)c)
			return (&save[i]);
		i++;
	}
	return (NULL);
}

/* calloc */
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* strjoin */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = 0;
	while (j < len2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

/* Free strjoin and return new string */
char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new_save;

	new_save = ft_strjoin(save, tmp);
	free(save);
	return (new_save);
}
