/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:00:25 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:09:49 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_zero(char *str, char *buf)
{
	long x;

	x = 0;
	if (x > 0)
		ft_strcpy(buf + x, buf);
	x = 0;
	if (buf[x] == '\n')
	{
		str = ft_strjoin_gnl(str, buf);
		return (1);
	}
	str = ft_strjoin_gnl(str, buf);
	if (ft_chrcmp(buf, '\n') == 0)
	{
		str = ft_strjoin_gnl(str, buf);
		return (1);
	}
	return (0);
}

int		get_next_backn(char *str, char *buf, int fd, size_t *error)
{
	while (ft_chrcmp (buf, '\n') == 1)
	error = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || error < 0)
		return (-1);
	buf[error] = '\0';
}
int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*str;
	long			error;

	error = 1;
	str = NULL;
	if (ft_chrcmp(buf, '\n') == 0)
	{
		if (get_next_zero(str, buf) == 1)
		{
			*line = ft_strdup(str);
			free(str);
			return (1);
		}
	}
	if (ft_chrcmp(buf, '\n') == 1 && error != 0)
	{

	}

}