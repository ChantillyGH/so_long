/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:40:31 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/31 17:58:51 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *str)
{
	char	*s;

	s = ft_strrchr(str, '.');
	if (!s)
		return (1);
	if (ft_strncmp(s, ".ber", 5))
	{
		print_error("Map extension is wrong");
		return (1);	
	}
	return (0);
}

char	**map_read(char **map, int fd, int i)
{
	char	*str;
	
	str = get_next_line(fd);
	if (str)
		map = map_read(map, fd, i + 1);
	else if (i)
	{
		wincall()->map_y = i;
		map = malloc(sizeof(char *) * (i + 1));
	}
	if (!map)
		return (NULL);
	wincall()->map_x = ft_strsize(str);
	map[i] = str;
	return (map);
	
}
int	letter_checker(char *map)
{
	int	i;
	int	j;

	i = ft_strlen(map - 1);
	j = -1;
	if (map[0] != '1' || map[i] != '1')
		print_error("Map is not closed");
	while (map[++j])
	{
		if (map[j] != '1' && map[j] != '0' && map[j] != 'E' && map[j] != 'C' \
		 && map[j] != 'P' && map[j] != 'X')
			print_error("Badly formatted map.");
	}
	return (0);
}