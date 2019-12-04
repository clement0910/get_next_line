/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: csapt <csapt@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:25:55 by csapt        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 18:42:19 by csapt       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_zero(char **str, char *buf);
int		get_next_backn(char **str, char *buf, int fd, long *error);
int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(char *str);
char	*ft_strdup(char *str);
int		ft_chrcmp(char *str, char c);
char	*ft_strcpy(char *src, char *dst);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_check_index(char *buf);
char	*ft_strjoin_cpy(char *s1);

#endif
