/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:54:37 by mdoroana          #+#    #+#             */
/*   Updated: 2022/10/17 16:44:35 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_code(int keycode)
{
	printf("%i\n", keycode);
	return (1);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_win *win;
	// t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "so_long");
	mlx_hook(mlx_win, 02, 1L << 0, close_win, &win);
	mlx_loop(mlx);
}
