/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:57:57 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/24 17:38:12 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		if (win->win)
			mlx_destroy_window(win->mlx, win->win);
		if (win->mlx)
		{
			mlx_destroy_display(win->mlx);
			free(win->mlx);
		}
		exit(0);
	}
	return (0);
}