/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:37 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/07 19:36:58 by mdoroana         ###   ########.fr       */
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
	int	fd;

	if (ac != 2)
		return (printf("WRONG NUMBER OF ARGUMENTS\n"));
	check_map(av[1]);
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error("It's a directory\n");
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error("File doesn't exist\n");
	(wincall())->map = map_read(NULL, fd, 0);
	(wincall())->mlx = mlx_init();
	(wincall())->win = mlx_new_window(wincall()->mlx, wincall()->map_x * 64, \
	wincall()->map_y * 64, "so_long");
	render();
	mlx_hook(wincall()->win, 02, 1L << 0, close_win, wincall());
	mlx_hook(wincall()->win, 17, 1L << 2, exit_game, wincall());
	mlx_loop(wincall()->mlx);
}
