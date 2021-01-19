/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csapt <csapt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:28:30 by csapt             #+#    #+#             */
/*   Updated: 2021/01/19 16:42:36 by csapt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlento(char *str, char c, int mode)
{
	int		x;

	x = -1;
	if (!str)
		return (0);
	if (mode)
	{
		while (str[++x])
			if (str[x] == c)
				return (1);
		return (0);
	}
	while (str[++x])
		if (str[x] == c)
			return (x);
	return (x);
}

char		*ft_strdup(char *src, int size)
{
	int		x;
	char	*ret;

	x = 0;
	if (!size)
		size = ft_strlento(src, '\n', 0);
	else
		size = BUFFER_SIZE;
	if (!(ret = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (src[x] != '\n' && src[x] != '\0')
	{
		ret[x] = src[x];
		x++;
	}
	ret[x] = '\0';
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	if (s1 == NULL)
		return (ft_strdup(s2, 0));
	if (!(str = malloc((ft_strlento(s1, '\0', 0) +
						ft_strlento(s2, '\n', 0) + 1) * sizeof(char))))
		return (NULL);
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] && s2[y] != '\n')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	free(s1);
	return (str);
}

void		sub_modif(char *str)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	x++;
	while (str[x] != '\0')
	{
		str[y] = str[x];
		x++;
		y++;
	}
	while (y < x)
	{
		str[y] = '\0';
		y++;
	}
}
