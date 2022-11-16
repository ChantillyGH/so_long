/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoroana <mdoroana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:59:17 by mdoroana          #+#    #+#             */
/*   Updated: 2022/11/16 16:22:53 by mdoroana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
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
	int		tmp_px;
	int		tmp_py;
	int		player_x;
	int		player_y;
	int		collec;
	int		vent_x;
	int		vent_y;
	int		p_count;
	int		e_count;
}			t_win;

void	print_error(char *str, int status);
int		exit_game(t_win *win);
t_win	*wincall(void);
int		check_map(char **av);
char	**map_read(char **map, int fd, int i);
int		valid_path(char **copy, int x, int y);
void	look_path(char **copy);
void	path_check(char **copy, int x, int y);
int		player_coord(char **copy);
int		letter_checker(char *map);
int		ft_maplength(char *str);
void	free_map(char **map);
int		border_check(t_win *win);
char	**map_copy(char **copy);
void	render(void);
void	img_load(int i);
void	img_load2(int i);
int		coords(int axis_x, int axis_y);
int		close_win(int keycode, t_win *win);
void	collect_check(t_win *win);
int		move_checker(int keycode, t_win *win);
int		player_movement(int keycode, t_win *win);
void	print_map(t_win *win, int index_c);
int		animation(t_win *win);

#endif