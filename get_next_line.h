/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:06 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/30 08:12:54 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h> 

typedef struct s_byte
{
	char			act_chr;
	struct s_byte	*next;
}				t_byte;

typedef struct s_file
{
	int		fd;
	int		len;
	int		pos;
	int		read;
	t_byte	*string;
	char	buffer[BUFFER_SIZE];
}				t_file;

char	*get_next_line(int fd);
char	*ft_read_line(t_file *make);
char	*ft_make_line(t_file *make);
void	to_the_last(t_byte **head, t_byte *node);
t_byte	*new_node(char byte);
char	*free_node(t_byte *node);

#endif