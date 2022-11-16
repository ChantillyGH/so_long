/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:30:18 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/16 13:23:43 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(char **copy)
{
	t_win	*win;
	char	**temp;
	int		i;

	win = wincall();
	temp = malloc(sizeof(char *) * (win->map_y + 1));
	if (!temp)
		print_error("Couldn't allocate copy", 1);
	i = -1;
	while (++i < win->map_y)
	{
		temp[i] = ft_strdup(copy[i]);
		if (!temp[i])
			print_error("Error on copy malloc", 1);	
	}
	temp[i] = NULL;
	return (temp);
}

void	path_check(char **copy, int x, int y)
{
	copy[x][y] = 'P';
	if (copy[x - 1][y] == 'C' || copy[x - 1][y] == '0')
		path_check(copy, x - 1, y);
	if (copy[x + 1][y] == 'C' || copy[x + 1][y] == '0')
		path_check(copy, x + 1, y);
	if (copy[x][y - 1] == 'C' || copy[x][y - 1] == '0')
		path_check(copy, x, y - 1);
	if (copy[x][y + 1] == 'C' || copy[x][y + 1] == '0')
		path_check(copy, x, y + 1);
}

int	valid_path(char **copy, int x, int y)
{
	char	**temp;

	temp = map_copy(wincall()->map);
	player_coord(temp);
	path_check(temp, wincall()->tmp_px, wincall()->tmp_py);
	y = -1;
	while (temp[++y])
	{
		x = -1;
		while (temp[y][++x])
		{
			if (temp[y][x] == 'C')
			{
				free_map(temp);
				print_error("Check map pathing", 1);
			}
			if (temp[y][x] == 'E' && (!(temp[y + 1][x] == 'P' || temp[y - 1] \
			[x] == 'P' || temp[y][x - 1] == 'P' && temp[y][x + 1] == 'P')))
			{
				free_map(temp);
				print_error("Check map pathing", 1);
			}
		}
	}
	free_map(temp);
}

int	player_coord(char **copy)
{
	int	i;
	int	j;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j] && copy[i][j] != '\n')
		{
			if (copy[i][j] == 'P')
			{
				wincall()->tmp_py = j;
				wincall()->tmp_px = i;
			}
		}
	}	
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free (map);
	}
}