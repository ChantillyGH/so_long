/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:37 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/28 18:48:23 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_code(int keycode)
{
	printf("%i\n", keycode);
	return (1);
}

int	main(int ac, char **av)
{
	static t_win 	win;
	// t_data	img;
	if (ac != 2)
		return (printf("WRONG NUMBER OF ARGUMENTS\n"));
	check_map(av[1]);
	win.mlx = mlx_init();
	printf("%i\n", wincall()->map_y);
	win.win = mlx_new_window(win.mlx, 300, win.map_y * 64, "so_long");
	mlx_hook(win.win, 02, 1L << 0, close_win, &win);
	mlx_hook(win.win, 17, 1L << 2, exit_game, &win);
	mlx_loop(win.mlx);
}
