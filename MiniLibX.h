/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniLibX.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/21 19:30:10 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include <X11/keysym.h>

#define B_WALL	'1'
#define B_EMPTY	'0'
#define B_EXIT	'E'
#define B_COLLECTABLE	'C'
#define B_PLAYER	'P'
#define B_FOE	'F'

typedef struct	s_board
{
	char	**map;
	int		height;
	int		width;
}				t_board;

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_colect
{
	int			starting;
	int			current;
	t_coords	*set;
}				t_colect;

typedef struct	s_sprites
{
	t_img		*p_player;
//	t_img		*p_player;
	t_img		*p_collectable;
//	t_img		*p_collectable;
	t_img		*p_exit;
//	t_img		*p_exit;
	t_img		*p_wall;
//	t_img		*p_wall;
	t_img		*p_empty;
//	t_img		*p_empty;
	t_img		*p_foe;
//	t_img		*p_foe;
	t_coords	size;
}				t_sprites;

typedef struct	s_params
{
	t_xvar		*mlx;
	t_win_list	*win;
	t_img		*main_img;
	t_sprites	*sprites;
	t_board		board;
	t_coords	player;
	t_colect	colect;
	t_coords	exit;
	int			moves;
}				t_params;

# define WINDOW_X 360
# define WINDOW_Y 240

// Imports
void	get_board(int height, int width, t_board *board, t_coords *player); // debugging mode
void	build_sprites(t_xvar *mlx, t_sprites *sprites);

// Window management
void	close_window(void *param_raw);
void	print_board(t_board board);

// Events
int		expose_funct(void *param_raw);
int		keyboard_events(int keycode, void *param_raw);

// Movement & Checkers
void	go_dir(void *param_raw, char dir);
void	check_collect(t_params *param);
void	check_wall(t_params *param, char dir);

// Visualisation
void	print_display(void *param_raw);

// Others
int		main(void);
void	*ft_out(t_params *params, int error);


#endif

/*
	sudo apt-get install x11-devel
	sudo apt-get install libx11-dev
	sudo apt-get install libbsd-dev

	cd minilibx-linux
	make all
	./minilibx-linux/test/mlx-test # run test!
*/