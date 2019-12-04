/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:00:25 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 15:20:16 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_index(char *buf)
{
    long	x;

    x = 0;
    while (buf[x] != '\0')
    {
        if (buf[x] == '\n')
        {
            x++;
            return (x);
        }
        x++;
    }
    return (-1);
}

int		get_next_zero(char **str, char *buf)
{
	long x;

	x = ft_check_index(buf);
	if (x > 0)
		ft_strcpy(buf + x, buf);
	x = 0;
	if (buf[x] == '\n')
	{
		*str = ft_strjoin_gnl(*str, buf);
		return (1);
	}
	*str = ft_strjoin_gnl(*str, buf);
	if (ft_chrcmp(buf, '\n') == 0)
	{
		*str = ft_strjoin_gnl(*str, buf);
		return (1);
	}
	return (0);
}

int		get_next_backn(char **str, char *buf, int fd, long *error)
{
	*error = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || *error < 0)
		return (-1);
	buf[*error] = '\0';
	*str = ft_strjoin_gnl(*str, buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*str;
	long			error;
	int				ret;

	error = 1;
	str = NULL;
	if (ft_chrcmp(buf, '\n') == 0)
	{
		if (get_next_zero(&str, buf) == 1)
		{
;			*line = ft_strdup(str);
			free(str);
			return (1);
		}
	}
	if (ft_chrcmp(buf, '\n') == 1 && error != 0)
	{
		ret = get_next_backn(&str, buf, fd, &error);
		if (ret == -1)
			return (-1);
		if (error == 0)
		{
			*line = ft_strdup(str);
			free(str);
			return (0);
		}
		while (ft_chrcmp(buf, '\n') == 1 && ret == 1)
		{
			get_next_backn(&str, buf, fd, &error);
			if (error == 0)
			{
				*line = ft_strdup(str);
				free(str);
				return (0);
			}
		}
	}
	*line = ft_strdup(str);
	free(str);
	return (1);
}

int main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("normal.txt", O_RDONLY);
	if (fd == -1)
	{	
		printf("File Error\n");
		return(1);
	}
	while (1)
	{
		ret = get_next_line(fd, &line);
		printf("[%d] [%d] '%s'\n", fd, ret, line);
		free(line);
		if (ret <= 0)
			break ;
	}
	close(fd);
	return (0);
}