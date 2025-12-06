/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:40:20 by jpedra-v          #+#    #+#             */
/*   Updated: 2025/11/28 16:46:03 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

/* --- Main functions --- */
char		*get_next_line(int fd);
char		*read_until_enter(int fd, char *save);
char		*make_line_from(char *save);
char		*the_rest(char *save);

/* --- Utils --- */
size_t		ft_strlen(char *s);
char		*ft_free_strjoin(char *save, char *tmp);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *save, int c);
void		*ft_calloc(size_t count, size_t size);

#endif
