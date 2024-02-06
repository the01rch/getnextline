/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:26:23 by redrouic          #+#    #+#             */
/*   Updated: 2024/01/29 20:01:42 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_charset(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	y;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while (i < ls1)
	{
		new[i] = s1[i];
		i++;
	}
	y = 0;
	while (y < ls2)
		new[i++] = s2[y++];
	new[i] = '\0';
	return (free(s1), new);
}
