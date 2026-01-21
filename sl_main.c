/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:58 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/21 19:34:16 by dmota-ri         ###   ########.fr       */
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

void get_board(int width, int height, t_board *board, t_coords *player)
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
	ft_putstr_fd("set walls\n", 1);
	map[(height) / 2][(width) / 2] = B_PLAYER;
	ft_printf("player located at %i x %i", (height) / 2, (width) / 2);
	board->height = height;
	board->width = width;
	board->map = map;
	player->x = (width) / 2;
	player->y = (height) / 2;
}

void build_sprites(t_xvar *mlx, t_sprites *sprites)
{
	t_coords	size_save;
	
	sprites->p_collectable = mlx_xpm_file_to_image(mlx, "sprites/collectable.xpm", &sprites->size.x, &sprites->size.y);
	size_save.x = sprites->size.x;
	size_save.y = sprites->size.y;
	sprites->p_empty = mlx_xpm_file_to_image(mlx, "sprites/empty.xpm", &sprites->size.x, &sprites->size.y);
	if (size_save.x != sprites->size.x || size_save.y != sprites->size.y)
		exit(-1);
	sprites->p_exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &sprites->size.x, &sprites->size.y);
	if (size_save.x != sprites->size.x || size_save.y != sprites->size.y)
		exit(-1);
	sprites->p_foe = mlx_xpm_file_to_image(mlx, "sprites/foe.xpm", &sprites->size.x, &sprites->size.y);
	if (size_save.x != sprites->size.x || size_save.y != sprites->size.y)
		exit(-1);
	sprites->p_player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &sprites->size.x, &sprites->size.y);
	if (size_save.x != sprites->size.x || size_save.y != sprites->size.y)
		exit(-1);
	sprites->p_wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &sprites->size.x, &sprites->size.y);
	if (size_save.x != sprites->size.x || size_save.y != sprites->size.y)
		exit(-1);
}

int main(void)
{
	t_params		params;
//	int 			fd;
	t_sprites	sprites;
	t_coords	main_wind;
	int			bpp;
	int			size_line;
	int			endian;
	
	ft_putstr_fd("start\n\n", 1);

	get_board(5, 6, &params.board, &params.player); // generates a 3 x 5 valid board, and put it inside the board struct (map (array), height, width)
	ft_putstr_fd("\n\npost get board\n\n", 1);

	print_board(params.board); // prints the board for visualisation purposed
	ft_putstr_fd("\n\npost print board\n\n", 1);
	params.mlx = mlx_init(); // initiates mlx
	ft_putstr_fd("\n\npost mlx_init\n", 1);
	build_sprites(params.mlx, &sprites); // opens sprite files and loads into an array of images
	ft_putstr_fd("\n\npost sprites\n", 1);
	mlx_get_data_addr(sprites.p_collectable, &bpp, &size_line, &endian);
	main_wind.x = sprites.size.x * params.board.width;
	main_wind.y = sprites.size.y * params.board.height;
	ft_printf("\n\nData: bpp - %i, size_line - %i, endian - %i res sprites - %i x %i res window - %i x %i\n",
		bpp, size_line, endian, sprites.size.x, sprites.size.y, main_wind.x, main_wind.y); // gets and prints data for visualisation purposed
	params.win = mlx_new_window(params.mlx, main_wind.x, main_wind.y, "Main Window"); // create window
	ft_putstr_fd("\n\npost Window\n", 1);
	params.main_img = mlx_new_image(params.mlx, main_wind.x, main_wind.y);
	ft_putstr_fd("\n\npost image\n", 1);
	mlx_put_image_to_window(params.mlx, params.win, sprites.p_wall, sprites.size.x * 0, sprites.size.y * 0);
	mlx_put_image_to_window(params.mlx, params.win, sprites.p_foe, sprites.size.x * 1, sprites.size.y * 0);
	ft_putstr_fd("\n\nEND!\n", 1);
	
	mlx_key_hook(params.win, keyboard_events, &params); // problem here

	mlx_expose_hook(params.win, expose_funct, &params); // and here
	ft_printf("end %i %i\n", params.player.x, params.player.y);
	mlx_loop(params.mlx);
	return (0);
}

//	t_img		*template_img;
//	t_coords	size_template;
//	template_img = mlx_xpm_file_to_image(mlx, "sprites/template.xpm", &size_template.x, &size_template.y);
//	mlx_put_image_to_window(mlx, window, template_img, size_sprite.x, size_sprite.y);
//	ft_putstr_fd("\n\nPrint Template test\n", 1);
