/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:40:03 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/07 18:43:20 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_load(int i)
{
	wincall()->img = malloc(12 * sizeof(void *));
	if (!wincall()->img)
		return ;
	(wincall())->img[0] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/collecf1.xpm", &i, &i);
	(wincall())->img[1] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/collecf2.xpm", &i, &i);
	(wincall())->img[2] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/collecf3.xpm", &i, &i);
	(wincall())->img[3] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/collecf4.xpm", &i, &i);
	(wincall())->img[4] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/enemy.xpm", &i, &i);
	(wincall())->img[5] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/exitclose.xpm", &i, &i);
	(wincall())->img[6] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/exitopen.xpm", &i, &i);
	(wincall())->img[7] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/floor.xpm", &i, &i);
	img_load2(i);
}

void	img_load2(int i)
{
	(wincall())->img[8] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/mcl.xpm", &i, &i);
	(wincall())->img[9] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/mcr.xpm", &i, &i);
	(wincall())->img[10] = mlx_xpm_file_to_image(wincall()->mlx, \
	"sprites/wall.xpm", &i, &i);
	(wincall())->img[11] = NULL;
}
