/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:40:31 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/16 14:28:16 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char **av)
{
	char	*s;
	int		fd;

	s = ft_strrchr(av[1], '.');
	if (!s)
		return (1);
	if (ft_strncmp(s, ".ber", 5))
	{
		print_error("Map extension is wrong", 1);
		return (1);	
	}
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
		print_error("It's a directory\n", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error("File doesn't exist\n", 1);
	(wincall())->map = map_read(NULL, fd, 0);
	close(fd);
	if (!border_check(wincall()))
		print_error("Map is not closed", 1);
	return (0);
}

char	**map_read(char **map, int fd, int i)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
	{
		letter_checker(str);
		map = map_read(map, fd, i + 1);
	}
	else if (i)
	{
		wincall()->map_y = i;
		map = malloc(sizeof(char *) * (i + 1));
	}
	if (!map)
		print_error("Map is empty", 1);
	wincall()->map_x = ft_maplength(str);
	map[i] = str;
	return (map);
}

int	letter_checker(char *map)
{
	int	j;

	j = -1;
	while (map[++j] != '\n' && map[j])
	{
		if (map[j] != '1' && map[j] != '0' && map[j] != 'E' && map[j] != 'C' \
		&& map[j] != 'P' && map[j] != 'X')
			print_error("Badly formatted map.", 1);
		if (map[j] == 'E')
			wincall()->e_count++;
		if (map[j] == 'P')
			wincall()->p_count++;
		if (map[j] == 'C')
			wincall()->collec++;
	}
	if (wincall()->p_count > 1)
		print_error("Multiplayer still not patched :(", 1);
	if (wincall()->e_count > 1)
		print_error("Multiple vents makes the SUS confused :(", 1);
	return (0);
}

int	border_check(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->map_x - 1)
	{
		if (win->map[0][i] != '1' || win->map[win->map_y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < win->map_y - 1)
	{
		if (win->map[i][0] != '1' || win->map[i][win->map_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_maplength(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
