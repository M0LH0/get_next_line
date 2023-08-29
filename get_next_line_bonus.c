/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:55:21 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/28 16:45:32 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file	file[1024];

	if (fd >= 0 && file[fd].pos >= file[fd].read)
	{
		file[fd].pos = 0;
		if (file[fd].buffer)
			free(file[fd].buffer);
		file[fd].buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof (char)));
		if (!file[fd].buffer)
			return (NULL);
		while (file[fd].pos < BUFFER_SIZE)
			file[fd].buffer[file[fd].pos++] = '\0';
		file[fd].pos = 0;
		file[fd].len = 0;
		file[fd].string = NULL;
		file[fd].fd = fd;
		file[fd].read = read(fd, file[fd].buffer, BUFFER_SIZE);
	}
	if (fd < 0 || fd > 1024 || file[fd].buffer[file[fd].pos] == '\0')
	{
		if (file[fd].buffer)
			free(file->buffer);
		return (NULL);
	}
	return (ft_read_line(&file[fd]));
}

char	*ft_read_line(t_file *make)
{
	make->len = 0;
	while (1)
	{
		to_the_last(&make->string, new_node(*(make->pos + make->buffer)));
		if (*(make->buffer + make->pos) == '\n'
			|| *(make->buffer + make->pos) == '\0')
			break ;
		make->pos++;
		make->len++;
		if (make->pos >= make->read)
		{
			if (make->buffer)
				free(make->buffer);
			make->buffer = malloc(BUFFER_SIZE + 1);
			make->pos = 0;
			make->read = read(make->fd, make->buffer, BUFFER_SIZE);
			if (make->read <= 0)
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

	if (make->string && make->read < 0)
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
