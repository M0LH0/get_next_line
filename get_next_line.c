/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:02 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/26 15:18:11 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(t_file *make);
static char	*ft_make_line(t_file *make);

char	*get_next_line(int fd)
{
	static t_file	file;

	if (file.pos >= file.read)
	{
		file.pos = 0;
		while (file.pos < BUFFER_SIZE)
			file.buffer[file.pos++] = '\0';
		file.pos = 0;
		file.len = 0;
		file.string = NULL;
		file.fd = fd;
		file.read = read(fd, file.buffer, BUFFER_SIZE);
	}
	if (file.fd < 0 || file.buffer[file.pos] == '\0')
		return (NULL);
	return (ft_read_line(&file));
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
			make->pos = 0;
			make->read = read(make->fd, make->buffer, BUFFER_SIZE);
			if (make->read <= 0)
			{
				if (make->string && make->read < 0)
					return (free(make->string), NULL);
				break ;
			}
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
