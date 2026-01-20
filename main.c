/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:58 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/20 11:10:14 by dmota-ri         ###   ########.fr       */
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

/*void *ft_out(t_params *params, int error)
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
}*/
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

/*void	print_display(void *param_raw)
{
	t_params *param;

	param = param_raw;

	mlx_put_image_to_window(param->xlm, param->win, param->main_img, 0, 0);
}*/

void	print_display(void *mlx, void *win, void *main_img)
{
	mlx_put_image_to_window(mlx, win, main_img, 0, 0);
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

/*void go_up(void *param_raw)
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
}*/

void close_window(void *param_raw)
{
	t_params *param;

	param = param_raw;
	mlx_destroy_window(param->xlm, param->win);
}
/*
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
	
}*/

void	print_board(t_board board)
{
	int i;
	int j;

	ft_putstr_fd("\nBoard Height: ", 1);
	ft_putnbr_fd(board.height, 1);
	ft_putstr_fd("\tBoard Width: ", 1);
	ft_putnbr_fd(board.width, 1);
	ft_putchar_fd('\n', 1);
	i = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width)
			ft_putchar_fd(board.map[i][j++], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void get_board(int height, int width, t_board *board)
{
	char **map;
	int i;
	int j;
	ft_putstr_fd("get board\n", 1);

	map = malloc(sizeof(char *) * height);
	i = 0;
	while (i < height)
		map[i++] = malloc(sizeof(char) * width);
	ft_putstr_fd("post memory\n", 1);
	i = 0;
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			map[i][j] = B_EMPTY;
			ft_putchar_fd(map[i][j], 1);
			j++;
		}
		i++;
	}
	ft_putstr_fd("set empty\n", 1);

	i = 0;
	while(i < height)
	{
		map[i][0] = B_WALL;
		map[i][width-1] = B_WALL;
		i++;
	}
	i = 0;
	while(i < width)
	{
		map[0][i] = B_WALL;
		map[height-1][i] = B_WALL;
		i++;
	}
	ft_putstr_fd("set walls", 1);

	ft_putchar_fd(map[0][0], 1);
	board->height = height;
	board->width = width;
	board->map = map;
}

void build_sprites(t_xvar *mlx, t_sprites *sprites, t_coords *size_sprite)
{
	t_coords	size_save;
	
	sprites->p_collectable = mlx_xpm_file_to_image(mlx, "sprites/collectable.xpm", &size_sprite->x, &size_sprite->y);
	size_save.x = size_sprite->x;
	size_save.y = size_sprite->y;
	sprites->p_empty = mlx_xpm_file_to_image(mlx, "sprites/empty.xpm", &size_sprite->x, &size_sprite->y);
	if (size_save.x != size_sprite->x || size_save.y != size_sprite->y)
		exit(-1);
	sprites->p_exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &size_sprite->x, &size_sprite->y);
	if (size_save.x != size_sprite->x || size_save.y != size_sprite->y)
		exit(-1);
	sprites->p_foe = mlx_xpm_file_to_image(mlx, "sprites/foe.xpm", &size_sprite->x, &size_sprite->y);
	if (size_save.x != size_sprite->x || size_save.y != size_sprite->y)
		exit(-1);
	sprites->p_player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &size_sprite->x, &size_sprite->y);
	if (size_save.x != size_sprite->x || size_save.y != size_sprite->y)
		exit(-1);
	sprites->p_wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &size_sprite->x, &size_sprite->y);
	if (size_save.x != size_sprite->x || size_save.y != size_sprite->y)
		exit(-1);
	
}

int main()
{
//	t_params		params;
//	int 			fd;
	t_board		board;
	t_img		*main_img;
	t_img		*template_img;
	t_win_list	*window;
	t_sprites	sprites;
	t_xvar		*mlx;
	t_coords	main_wind;
	t_coords	size_sprite;
	t_coords	size_template;
	int			bpp;
	int			size_line;
	int			endian;
	
	ft_putstr_fd("start\n\n", 1);

	get_board(5, 3, &board);
	ft_putstr_fd("\n\npost get board\n\n", 1);

	print_board(board);
	ft_putstr_fd("\n\npost print board\n\n", 1);
	mlx = mlx_init();
	ft_putstr_fd("\n\npost mlx_init\n", 1);
	build_sprites(mlx, &sprites, &size_sprite);
	ft_putstr_fd("\n\npost sprites\n", 1);
	mlx_get_data_addr(sprites.p_collectable, &bpp, &size_line, &endian);
	main_wind.x = size_sprite.x * board.width;
	main_wind.y = size_sprite.y * board.height;
	ft_printf("\n\nData: bpp - %i, size_line - %i, endian - %i res sprites - %i x %i res window - %i x %i\n",
		bpp, size_line, endian, size_sprite.x, size_sprite.y, main_wind.x, main_wind.y);
	window = mlx_new_window(mlx, main_wind.x, main_wind.y, "Main Window");
	ft_putstr_fd("\n\npost Window\n", 1);
	main_img = mlx_new_image(mlx, main_wind.x, main_wind.y);
	ft_putstr_fd("\n\npost image\n", 1);
	mlx_put_image_to_window(mlx, window, sprites.p_foe, size_sprite.x * 0, size_sprite.y * 0);
	ft_putstr_fd("\n\nEND!\n", 1);
	mlx_loop(mlx);
	return (0);
}

//	template_img = mlx_xpm_file_to_image(mlx, "sprites/template.xpm", &size_template.x, &size_template.y);
//	mlx_put_image_to_window(mlx, window, template_img, size_sprite.x, size_sprite.y);
//	ft_putstr_fd("\n\nPrint Template test\n", 1);
