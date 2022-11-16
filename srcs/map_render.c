/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:47:11 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/16 14:46:51 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render(void)
{
	int	x;
	int	y;

	img_load(64);
	y = -1;
	while (wincall()->map[++y])
	{
		x = -1;
		while (wincall()->map[y][++x] && wincall()->map[y][x] != '\n')
		{
			coords(x, y);
			mlx_put_image_to_window(wincall()->mlx, wincall()->win, \
			wincall()->img[(wincall()->map[y][x] == 'P') * 8 + \
			(wincall()->map[y][x] == 'C') * 0 + (wincall()->map[y][x] == 'X') \
			* 4 + (wincall()->map[y][x] == '1') * 10 + (wincall()->map[y][x] == \
			'0') * 7 + ((!wincall()->collec && wincall()->map[y][x] == 'E') * 6 \
			+ (wincall()->collec && wincall()->map[y][x] == 'E') * 5)], \
			x * 64, y * 64);
		}
	}
}

int	coords(int axis_x, int axis_y)
{
	int	x;
	int	y;

	x = axis_x;
	y = axis_y;
	if (wincall()->map[y][x] == 'P')
	{
		wincall()->player_x = x * 64;
		wincall()->player_y = y * 64;
	}
	if (wincall()->map[y][x] == 'E')
	{
		wincall()->vent_x = y;
		wincall()->vent_y = x;
	}
	return (0);
}

int	animation(t_win *win)
{
	static int	frame = 0;
	static int	index_c = 0;

	frame++;
	if (frame == 1000)
	{
		print_map(win, index_c);
		index_c++;
		frame = 0;
		if (index_c == 4)
			index_c = 0;
	}
	return (0);
}

void	print_map(t_win *win, int index_c)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[++i])
	{
		j = 0;
		while (win->map[i][++j] && win->map[i][j] != '\n')
		{
			if (win->map[i][j] == 'C')
			{
				mlx_put_image_to_window(win->mlx, win->win, \
				win->img[index_c], j * 64, i * 64);
			}
		}
	}
}
