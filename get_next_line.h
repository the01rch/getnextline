/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:26:18 by redrouic          #+#    #+#             */
/*   Updated: 2024/01/29 19:48:53 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		is_charset(char *s);
char	*get_next_line(int fd);

#endif
