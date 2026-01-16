/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:58 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/15 18:01:22 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniLibX.h"

/*
	sudo apt-get install x11-devel
	sudo apt-get install libx11-dev
	sudo apt-get install libbsd-dev

	cd minilibx-linux
	make all
	./minilibx-linux/test/mlx-test # run test!
*/

void *ft_out(t_params *params, int error)
{
	if (params)
	{
		trash_2d_char(params->board->map);
		trash_2d_int(params->collectables);
	}
	if (error)
	{
		printf("ERROR\n");
		exit(error);
	}
	return (NULL);
}
/*
int main(void)
{
	t_xvar		*workspace;
	t_win_list	*window;
	char buff;
	
	printf("pre process\n");
	if (!(workspace = mlx_init()))
		ft_out(NULL, 1);
	printf("create workspace\n");

	
	window = mlx_new_window(workspace, WINDOW_X, WINDOW_Y, "New Window");
	if (!window)
		ft_out(NULL, 2);
	printf("create Window\n");
	mlx_pixel_put(workspace, window, 20, 20, 0x0000FF00);
	mlx_pixel_put(workspace, window, 30, 30, 0x00FF0000);
	mlx_pixel_put(workspace, window, 40, 40, 0x000000ff);
	printf("Print Pixels\n waiting for confirmation");
	read(STDIN_FILENO, &buff, 1);

	printf("pixel search? %x\n", mlx_get_color_value(workspace, 0x000000ff));
	mlx_clear_window(workspace, window);
	printf("Clear Window\n waiting for confirmation");
	read(STDIN_FILENO, &buff, 1);
	
	int x;
	int y;
	
	t_img *xpm_img = mlx_xpm_file_to_image(workspace, "img.xpm", &x, &y);
	if (!xpm_img)
	{
		printf("image not ready: ");
		ft_out(NULL, 3);
	}
	printf("create Load image %d,%d\n", x, y);
	int val = 1;
	mlx_put_image_to_window(workspace, window, xpm_img, 0, 0);
	printf("Immage displayed Size %i x %i\n waiting for confirmation", x, y);
	read(STDIN_FILENO, &buff, 1);
	
	// A4CAF1 - blue
	// 7C842D - green

	mlx_clear_window(workspace, window);
	printf("Clear Window\n waiting for confirmation");
	read(STDIN_FILENO, &buff, 1);


	
	
	
	mlx_clear_window(workspace, window);
	printf("Clear Window\n waiting for confirmation");
	read(STDIN_FILENO, &buff, 1);
	
	
	mlx_destroy_window(workspace, window);
	if (!workspace)
		ft_out(NULL, 4);
	printf("Window Destroyed\n");

	
	return 0;
}
*/

void	print_display(void *param_raw)
{
	t_params *param;

	param = param_raw;

	mlx_put_image_to_window(param->xlm, param->win, param->main_img, 0, 0);
}
void	check_collect(t_params *param, char dir)
{
	if (param->board->map[param->player.x][param->player.y] == B_WALL)
	{
		param->player.x = param->player.x - (dir == 's') + (dir == 'n');
		param->player.y = param->player.y + (dir == 'e') - (dir == 'w');
	}
	else
		param->moves++;
}

void	check_wall(t_params *param, char dir)
{
	if (param->board->map[param->player.x][param->player.y] == B_WALL)
	{
		param->player.x = param->player.x - (dir == 's') + (dir == 'n');
		param->player.y = param->player.y + (dir == 'e') - (dir == 'w');
	}
	else
		param->moves++;
}

void go_up(void *param_raw)
{
	t_params *param;

	param = param_raw;
	
	param->player.y--;
	check_wall(param, 'n');
	check_collect(param, 'n');
	print_display(param);
}

void go_right(void *param_raw)
{
	t_params *param;

	param = param_raw;
	
	param->player.x++;
	check_wall(param, 'e');
	check_collect(param, 'e');
	print_display(param);
}

void go_left(void *param_raw)
{
	t_params *param;

	param = param_raw;
	
	param->player.x--;
	check_wall(param, 'w');
	check_collect(param, 'w');
	print_display(param);
}

void go_down(void *param_raw)
{
	t_params *param;

	param = param_raw;
	
	param->player.y++;
	check_wall(param, 's');
	check_collect(param, 's');
	print_display(param);
}

void close_window(void *param_raw)
{
	t_params *param;

	param = param_raw;
	mlx_destroy_window(param->xlm, param->win);
}

void keyboard_events(int keycode, void *param)
{
	if (keycode == XK_Escape)
		close_window(param);
	else if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		go_up(param);
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		go_right(param);
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		go_left(param);
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		go_down(param);
	
}

int str_to_map_check(t_params *params, char *file_line)
{
	int old_len;

	old_len = params->board->width;
	while (file_line || *file_line != '\n')
	{
		params->board->map[params->board->height][params->board->width] = *file_line++;
		if (params->board->map[params->board->height][params->board->width] == B_WALL
			|| params->board->map[params->board->height][params->board->width] == B_EMPTY
			|| params->board->map[params->board->height][params->board->width] == B_FOE)
			continue ;
		else if (params->board->map[params->board->height][params->board->width] != B_COLLECTABLE)
			params->collectables += add_collectable(params, params->board->height, params->board->width);
		else if (params->board->map[params->board->height][params->board->width] != B_EXIT)
			params->exit++;
		else if (params->board->map[params->board->height][params->board->width] != B_PLAYER)
			params->player++;
		else
			return (1);
		params->board->width++;
	}
	if ((old_len && old_len != params->board->width) && params->board->map[params->board->height][params->board->width] == B_WALL && params->board->map[params->board->height][0] == B_WALL)
		return (1);
	return (0);
}

int check_all_wall(t_board *board)
{
	int i;

	i = 0;
	while (i >= board->width)
	{
		if (!(board->map[board->height][i] == B_WALL))
			return (0);
		i++;
	}
	return (1);
}

t_board	*file_to_board_matrix(int fd, t_params *params)
{
	char	*file_line;
	t_board	*board;

	file_line = NULL;
	board = ft_calloc(sizeof(t_board), 1);
	while(!(!file_line && board))
	{
		file_line = get_next_line(fd);
		if (!file_line)
			break;
		if (str_to_map_check(params, file_line))
			return (ft_out(params, 1));
		if (!board->height)
			if (!check_all_wall(board))
				return (free(file_line), ft_out(params, 1));
		free(file_line);
		board->height++;
	}
	if (check_all_wall(board) && (board->height - 2) * (board->width - 2) <= 3
		&& params->exit == 1 && params->player == 1 && params->collectables <= 1)
		return (board);
	return (ft_out(params, 1));
}

void	print_board(t_board board)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i > board.height)
	{
		while (j > board.width)
			ft_putchar_fd(board.map[i][j++], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int check_file(char const *name)
{
	size_t len;
	len = ft_strlen(name);
	if (name[len - 1] == 'r' && name[len - 2] == 'e'
		&& name[len - 3] == 'b' && name[len - 4] == '.')
		return (0);
	return (1);
}

int main(int argc, char const *argv[])
{
	t_params		params;
	int 			fd;

	if (argc != 2)
		return (1);
	if (!check_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	params.board = file_to_board_matrix(fd, &params);
	close(fd);
	if (!params.board)
		return (1);
	print_board(*params.board);
	return (0);
}
