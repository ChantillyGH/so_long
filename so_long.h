/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:59:17 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/11 18:35:46 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	**img;
	char	**map;
	int		map_y;
	int		map_x;
	int		player_x;
	int		player_y;
	int		collec;
	int		vent_x;
	int		vent_y;
}			t_win;

int		close_win(int keycode, t_win *win);
int		check_map(char *str);
int		letter_checker(char *map);
void	print_error(char *str, int status);
int		exit_game(t_win *win);
char	**map_read(char **map, int fd, int i);
t_win	*wincall(void);
int		letter_checker(char *map);
void	img_load(int i);
void	img_load2(int i);
void	render(void);
int		ft_maplength(char *str);
void	collect_check(t_win *win);
int		move_checker(int keycode, t_win *win);
int		player_movement(int keycode, t_win *win);

#endif