/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:57:57 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/15 20:02:03 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str, int status)
{
	if (status)
		ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit_game(wincall());
}

int	exit_game(t_win *win)
{
	int	i;

	i = 0;
	if (win->map)
	{
		while (win->map[i])
			free(win->map[i++]);
		free (win->map);
	}
	i = 0;
	if (win->img)
	{
		while (i < 11)
			mlx_destroy_image(win->mlx, win->img[i++]);
		free(win->img);
	}
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(0);
	return (0);
}

t_win	*wincall(void)
{
	static t_win	win;

	return (&win);
}