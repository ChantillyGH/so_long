/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:52 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/11 19:06:34 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(int keycode, t_win *win)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_checker(keycode, win);
	else if (keycode == ESC)
		exit_game(win);
	return (0);
}

int	player_movement(int keycode, t_win *win)
{
	static int	steps = 0;
	char		*str;

	mlx_put_image_to_window(win->mlx, win->win, win->img[7], win->player_x, \
	win->player_y);
	win->player_x += (((keycode == D) - (keycode == A)) * 64);
	win->player_y += (((keycode == S) - (keycode == W)) * 64);
	mlx_put_image_to_window(win->mlx, win->win, win->img[(keycode == A) * 8 \
	+ (keycode == D) * 9 + (keycode == W) * 9 + (keycode == S) * 8],\
	win->player_x, win->player_y);
	steps++;
	str = ft_itoa(steps);
	mlx_put_image_to_window(win->mlx, win->win, win->img[10], 0, 0);
	mlx_string_put(win->mlx, win->win, 10, 10, 0xFFFFFF, str);
	free(str);
	collect_check(win);
	return (0);
}

int	move_checker(int keycode, t_win *win)
{
	int	x;
	int	y;

	y = win->player_y / 64;
	x = win->player_x / 64;
	if ((keycode == W && win->map[y - 1][x] != '1') \
	&& (win->map[y - 1][x] != 'E' || !win->collec))
		player_movement(keycode, win);
	else if (keycode == S && win->map[y + 1][x] != '1' \
	&& (win->map[y + 1][x] != 'E' || !win->collec))
		player_movement(keycode, win);
	else if (keycode == A && win->map[y][x - 1] != '1' \
	&& (win->map[y][x - 1] != 'E' || !win->collec))
		player_movement(keycode, win);
	else if (keycode == D && win->map[y][x + 1] != '1' \
	&& (win->map[y][x + 1] != 'E' || !win->collec))
		player_movement(keycode, win);
	return (0);
}

void	collect_check(t_win *win)
{
	int	x;
	int	y;

	x = win->player_x / 64;
	y = win->player_y / 64;
	if (win->map[y][x] == 'C')
	{
		win->map[y][x] = '0';
		win->collec--;
		if (!win->collec)
			mlx_put_image_to_window(win->mlx, win->win, win->img[6], \
			win->vent_y * 64, win->vent_x * 64);
	}
	if (win->map[y][x] == 'X')
		print_error("The alien impaled you :(", 0);
	if (win->map[y][x] == 'E' && win->collec == 0)
		print_error("The SUS wins!", 0);
}