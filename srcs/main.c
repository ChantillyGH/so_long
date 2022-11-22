/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:37 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/22 16:40:44 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		print_error("WRONG NUMBER OF ARGUMENTS\n", 1);
	if (check_map(av))
		print_error("Invalid map name", 1);
	(valid_path(wincall()->map, 0, 0));
	(wincall())->mlx = mlx_init();
	(wincall())->win = mlx_new_window(wincall()->mlx, wincall()->map_x * 64, \
	wincall()->map_y * 64, "so_long");
	render();
	mlx_hook(wincall()->win, 02, 1L << 0, close_win, wincall());
	mlx_hook(wincall()->win, 17, 1L << 2, exit_game, wincall());
	mlx_loop_hook(wincall()->mlx, animation, wincall());
	mlx_loop(wincall()->mlx);
}
