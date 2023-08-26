/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:08:04 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/26 08:37:54 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_byte	*new_node(char byte)
{
	t_byte	*chr;

	chr = (t_byte *)malloc(sizeof(t_byte));
	chr->act_chr = byte;
	chr->next = NULL;
	return (chr);
}

void	to_the_last(t_byte **head, t_byte *node)
{
	t_byte	*reposition;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	reposition = *head;
	while (reposition->next)
		reposition = reposition->next;
	reposition->next = node;
}
