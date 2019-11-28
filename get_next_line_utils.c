/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:25:29 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:09:47 by csapt       ###    #+. /#+    ###.fr     */
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
