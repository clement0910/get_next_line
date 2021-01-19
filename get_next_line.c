/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:28:37 by csapt             #+#    #+#             */
/*   Updated: 2021/01/19 16:26:44 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char *buf = NULL;
	long		error;

	*line = NULL;
	if ((buf == NULL && !(buf = ft_strdup("", 1))) ||
			((error = 1) == 1 && (fd < 0 || !line || BUFFER_SIZE <= 0)))
		return (-1);
	if (ft_strlento(buf, '\n', 1))
	{
		sub_modif(buf);
		*line = ft_strjoin(*line, buf);
		if (ft_strlento(buf, '\n', 1))
			return (1);
	}
	while (ft_strlento(buf, '\n', 1) == 0 && error != 0)
	{
		error = read(fd, buf, BUFFER_SIZE);
		if (fd < 0 || error < 0)
			return (-1);
		buf[error] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	(error == 0) ? free(buf) : 0;
	(error == 0) ? buf = NULL : 0;
	return ((error == 0) ? 0 : 1);
}
