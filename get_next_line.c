/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:26:10 by redrouic          #+#    #+#             */
/*   Updated: 2024/01/29 19:45:39 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*last_str(char	*src)
{
	char	*str;
	int		i;
	int		y;

	if (!src || !src[0])
		return (0);
	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (str == NULL)
		return (0);
	y = 0;
	while (y <= i)
	{
		str[y] = src[y];
		y++;
	}
	str[y] = '\0';
	return (str);
}

char	*move2left(char *str)
{
	char	*left;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		return (free(str), NULL);
	left = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!left)
		return (free(left), NULL);
	j = 0;
	i++;
	while (str[i])
		left[j++] = str[i++];
	left[j] = '\0';
	return (free(str), left);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	int			bread;

	if (BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	bread = 1;
	while (!is_charset(str) && bread)
	{
		bread = read(fd, buf, BUFFER_SIZE);
		if (bread == -1)
			return (free(buf), NULL);
		buf[bread] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(buf), NULL);
	}
	line = last_str(str);
	str = move2left(str);
	return (free(buf), line);
}
