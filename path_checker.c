/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:30:18 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/15 19:07:57 by mdoroana         ###   ########.fr       */
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
	copy[y][x] = 'P';
	// printf("%i\n %i\n", y, x);
	if (copy[y - 1][x] == 'C' || copy[y - 1][x] == '0')
		path_check(copy, x, y - 1);
	if (copy[y + 1][x] == 'C' || copy[y + 1][x] == '0')
		path_check(copy, x, y + 1);
	if (copy[y][x - 1] == 'C' || copy[y][x + 1] == '0')
		path_check(copy, x - 1, y);
	if (copy[y][x + 1] == 'C' || copy[y][x + 1] == '0')
		path_check(copy, x + 1, y);
}

int	valid_path(char **copy, int x, int y)
{
	char	**temp;

	temp = map_copy(copy);
	// for (int i = 0; i < wincall()->map_y; i++)
	// 	printf("%s\n", temp[i]);
	// printf("%i\n %i\n", wincall()->player_y, wincall()->player_x);
	// path_check(temp, wincall()->player_x / 64, wincall()->player_y / 64); 
	// for (int i = 0; i < wincall()->map_y; i++)
	// 	printf("%s\n", temp[i]);
}

int	player_coord(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map[++i][j])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (win->map[i][j] == 'P')
			{
				wincall()->player_x = j * 64;
				wincall()->player_y = i * 64;
				printf("%i\n %i\n", wincall()->player_y, wincall()->player_x);

			}
		}
	}
	return (0);
}