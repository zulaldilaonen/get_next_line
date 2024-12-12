/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:30:19 by zuonen            #+#    #+#             */
/*   Updated: 2024/12/12 14:01:57 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*multiread(char *str, int fd)
{
	char	*l;
	int		lw;

	l = malloc(((unsigned long long)BUFFER_SIZE + 1) * sizeof(char));
	if (!l)
		return (NULL);
	lw = 1;
	while (lw != 0 && !(ft_strchr(str, '\n')))
	{
		lw = read(fd, l, BUFFER_SIZE);
		if (lw == -1)
		{
			free(l);
			free(str);
			return (NULL);
		}
		l[lw] = '\0';
		str = ft_strjoin(str, l);
	}
	free(l);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = multiread(str, fd);
	if (!str)
		return (NULL);
	line = liner(str);
	str = next(str);
	return (line);
}
