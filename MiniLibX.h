/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniLibX.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/15 20:17:35 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
//#include "libft/get_next_line.h"
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
}				t_sprites;

typedef struct	s_params
{
	t_xvar		*xlm;
	t_win_list	*win;
	t_img		*main_img;
	t_sprites	*sprites;
	t_board		*board;
	t_coords	player;
	t_coords	exit;
	t_coords	*collectables;
	int			moves;
}				t_params;

# define WINDOW_X 360
# define WINDOW_Y 240


#endif
