/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:55:21 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/30 08:10:27 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file	fl[1024];

	if (fd >= 0 && fl[fd].pos >= fl[fd].rd)
	{
		fl[fd].pos = 0;
		if (fl[fd].buff)
			free(fl[fd].buff);
		fl[fd].buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof (char)));
		if (!fl[fd].buff)
			return (NULL);
		while (fl[fd].pos < BUFFER_SIZE)
			fl[fd].buff[fl[fd].pos++] = '\0';
		fl[fd].pos = 0;
		fl[fd].len = 0;
		fl[fd].string = NULL;
		fl[fd].fd = fd;
		fl[fd].rd = read(fd, fl[fd].buff, BUFFER_SIZE);
	}
	if (fd < 0 || fd > 1024 || fl[fd].rd < 0 || fl[fd].buff[fl[fd].pos] == '\0')
	{
		free(fl[fd].buff);
		fl[fd].buff = NULL;
		return (NULL);
	}
	return (ft_read_line(&fl[fd]));
}

char	*ft_read_line(t_file *make)
{
	make->len = 0;
	while (1)
	{
		to_the_last(&make->string, new_node(*(make->pos + make->buff)));
		if (*(make->buff + make->pos) == '\n'
			|| *(make->buff + make->pos) == '\0')
			break ;
		make->pos++;
		make->len++;
		if (make->pos >= make->rd)
		{
			if (make->buff)
				free(make->buff);
			make->buff = malloc(BUFFER_SIZE + 1);
			make->pos = 0;
			make->rd = read(make->fd, make->buff, BUFFER_SIZE);
			if (make->rd <= 0)
				break ;
		}
	}
	make->pos++;
	make->len++;
	return (ft_make_line(make));
}

char	*ft_make_line(t_file *make)
{
	t_byte	*next;
	char	*line;
	int		i;

	if (make->string && make->rd < 0)
	{
		free_node(make->string);
		return (NULL);
	}
	line = (char *)malloc((make->len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	next = NULL;
	while (make->string)
	{
		next = make->string->next;
		*(line + i) = make->string->act_chr;
		free(make->string);
		make->string = next;
		i++;
	}
	*(line + i) = '\0';
	return (line);
}
