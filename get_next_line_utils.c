/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:25:29 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 11:12:57 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen_gnl(char *str)
{
    size_t x;

    x = 0;
    while(str[x] != '\0' && str[x] != '\n')
    {
        x++;
    }
    return (x);
}

char	*ft_strdup(char *str)
{
	int x;
	int i;
	char *strs;

	x = 0;
	i = ft_strlen_gnl(str);
	if (!(strs = malloc(i + 1 * sizeof(char))))
		return 0;
	while (x < i)
	{
		strs[x] = str[x];
		x++;
	}
	strs[x] = '\0';
	return (strs);
}

int     ft_chrcmp(char *str, char c)
{
        int x;

        x = 0;
        while (str[x] != '\0')
        {
                if (str[x] == c)
                        return (0);
                x++;
        }
        return (1);
}

char	*ft_strcpy(char *src, char *dst) //ici erreur
{
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	while (dst[x] != '\0')
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		x;
	int		i;
	char	*str;

	x = 0;
	i = 0;
	if (s1 == NULL)
	{
		if (!(str = malloc(BUFFER_SIZE + 1)))
			return(NULL);
		while (s2[x] != '\0' && s2[x] != '\n')
		{
			str[x] = s2[x];
			x++;
		}
		str[x] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(ft_strlen_gnl((char *)s1) + ft_strlen_gnl((char *)s2) + 1)))
		return (NULL);
	while (s1[x] != '\0' && s1[x] != '\n')
	{
		str[i] = s1[x];
		x++;
		i++;
	}
	free(s1);
	x = 0;
	while (s2[x] != '\0' && s2[x] != '\n')
	{
		str[i] = s2[x];
		x++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_check_zero(char *str)
{
	size_t i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] != '\0')
		{	
			return (1);
		}
		i++;
	}
	return (0);
}