/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:24:44 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/21 21:41:52 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			nbytes;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	nbytes = 1;
	while (1)
	{
		if (!buff[0])
			nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes > 0)
			line = ft_strenter(buff, line);
		if (ft_findchr(buff) || nbytes < 1)
			break ;
	}
	return (line);
}
