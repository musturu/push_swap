/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:40:01 by lmoricon          #+#    #+#             */
/*   Updated: 2024/02/12 10:43:06 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			readr;
	int			i;

	i = 0;
	readr = 1;
	line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readr >= 0 && hasnl(line) == 0)
	{
		if (!*buf)
			readr = read(fd, buf, BUFFER_SIZE);
		if (readr <= 0)
			break ;
		i++;
		line = ft_strealloc(line, i);
		cat_n_rem(line, buf, 1);
	}
	if (line && *line)
		return (line);
	free(line);
	return (0);
}
