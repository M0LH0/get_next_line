/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-p <lsilva-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:28:16 by lsilva-p          #+#    #+#             */
/*   Updated: 2023/08/31 10:22:17 by lsilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	const char	*file_name = "ascii.txt";
	char		*c_line;
	int			file_descriptor;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		printf("Not able to open the file %s\n", file_name);
		return (1);
	}
	while ((c_line = get_next_line(file_descriptor)) != NULL)
	{
		printf("Line -> %s", c_line);
		usleep(500 * 1000);
		free(c_line);
	}
	close(file_descriptor);
	return (0);
}

