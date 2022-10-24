/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:37 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/24 17:38:44 by mdoroana         ###   ########.fr       */
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
	t_win 	win;
	// t_data	img;
	if (ac != 2)
		return (printf("WRONG NUMBER OF ARGUMENTS\n"));
	check_map(av[1]);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 300, 300, "so_long");
	mlx_hook(win.win, 02, 1L << 0, close_win, &win);
	mlx_loop(win.mlx);
}
