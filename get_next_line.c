/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:03:46 by mkgosise          #+#    #+#             */
/*   Updated: 2017/12/10 14:58:06 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*store_str(char *str)
{
	static char	*ret;

	if (!str)
	{
		if (!ret)
		{
			return (ft_strnew(0));
			return (NULL);
		}
		return (ret);
	}
	if (str)
		return ((ret = str));
	return (NULL);
}

int		write_into_line(char *ln, char **line)
{
	int i;

	if (!ft_strchr(ln, '\n') && !ft_strchr(ln, '\v') && !ft_strlen(store_str(NULL)))
		return (0);
	i = 0;
	while (ln[i] && (ln[i] != '\n' && ln[i] != '\v'))
		i++;
	store_str(ft_strdup(&ln[i + 1]));
	ft_bzero((void*)&ln[i], ft_strlen(&ln[i]));
	*line = ft_strdup(ln);
	ft_strdel(&ln);
	if (!ft_strlen(*line)){
		return (write_into_line(store_str(NULL), line));
	}
	/*if (!ft_strlen(store_str(NULL)))
		return (0);*/
	return (1);
}

int		readline(const int fd, char **line)
{
	int		rd;
	char	*tmp;
	char	*ln;
	char	buff[BUFF_SIZE + 1];

	ln = store_str(NULL);
	if (write_into_line(ln, line))
		return (1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (rd < 0){
			return (-1);
		}
		buff[rd] = 0;
		tmp = ft_strjoin(ln, buff);
		ft_strdel(&ln);
		ln = tmp;
		if (write_into_line(ln, line))
			return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	if (!line){
		return (-1);
	}
	return (readline(fd, line));
}
