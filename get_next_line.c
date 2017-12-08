/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:03:46 by mkgosise          #+#    #+#             */
/*   Updated: 2017/12/08 11:46:06 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int		readline(const int fd, char **line)
{
	int		rd;
	int		loops = 0;
	char	buff[BUFF_SIZE + 1];

	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		loops++;
		buff[rd] = 0;
		printf("\nInfo: [rd => %i, loops => %i]\n", rd, loops);
		printf("!@> %s", buff);
		break ;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	readline(fd, line);
	return (0);
	//return (readline(fd, line));
}
