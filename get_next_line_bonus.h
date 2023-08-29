/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:48:39 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/28 09:19:56 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h> 

typedef struct t_byte
{
	char			act_chr;
	struct t_byte	*next;
}				t_byte;

typedef struct s_file
{
	int		fd;
	int		len;
	int		pos;
	int		read;
	t_byte	*string;
	char	*buffer;
}				t_file;

char	*get_next_line(int fd);
char	*ft_read_line(t_file *make);
char	*ft_make_line(t_file *make);
void	to_the_last(t_byte **head, t_byte *node);
t_byte	*new_node(char byte);
char	*free_node(t_byte *node);

#endif