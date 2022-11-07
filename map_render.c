/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:47:11 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/07 19:28:57 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (wincall()->map[y][x] == 'P')
			{
				wincall()->player_x = x * 64;
				wincall()->player_y = y * 64;
			}
			if (wincall()->map[y][x] == 'C')
				wincall()->collec++;
			mlx_put_image_to_window(wincall()->mlx, wincall()->win, \
			wincall()->img[(wincall()->map[y][x] == 'P') * 8 + \
			(wincall()->map[y][x] == 'C') * 0 + (wincall()->map[y][x] == \
			'E') * 5 + (wincall()->map[y][x] == 'X') * 4 + \
			(wincall()->map[y][x] == '1') * 10 + (wincall()->map[y][x] == \
			'0') * 7], x * 64, y * 64);
		}
	}
}
