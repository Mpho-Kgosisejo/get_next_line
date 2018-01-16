/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:03:46 by mkgosise          #+#    #+#             */
/*   Updated: 2018/01/16 16:46:39 by mkgosise         ###   ########.fr       */
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
			return ((ret = ft_strnew(0)));
		return (ret);
	}
	if (str)
		return ((ret = str));
	return (NULL);
}

int		write_into_line(char *ln, char **line, int repeat)
{
	int i;

	if (!ft_strchr(ln, '\n'))// && !ft_strlen(store_str(NULL)))
		return (0);
	i = 0;
	while (ln[i] && ln[i] != '\n')
		i++;
	store_str(ft_strdup(&ln[i + 1]));
	//ft_bzero((void*)&ln[i], ft_strlen(&ln[i]));
	if (repeat)
		ft_strdel(line);
	*line = ft_strsub(ln, 0, i);// ft_strdup(ln);
	//free(ln);
	ft_strdel(&ln);
	/*if (!ft_strlen(*line)){
		return (write_into_line(store_str(NULL), line, 1));
	}*/
	/*if (!ft_strlen(store_str(NULL)))
		return (0);*/
	/*free(ln);
	ln = NULL;*/
	return (1);
}

int		readline(const int fd, char **line)
{
	int		rd;
	char	*tmp;
	char	*ln;
	char	buff[BUFF_SIZE + 1];

	ln = store_str(NULL);
	if (write_into_line(ln, line, 0))
		return (1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		buff[rd] = 0;
		tmp = ft_strjoin(ln, buff);
		/*free(ln);
		ln = NULL;*/
		ft_strdel(&ln);
		ln = tmp;
		if (write_into_line(ln, line, 0))
			return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	if (!line){
		return (-1);
	}
	//ft_strdel(line);
	return (readline(fd, line));
}
