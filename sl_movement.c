/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:36:02 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/21 19:44:48 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniLibX.h"

void	check_collect(t_params *param)
{
	int i;

	i = 0;
	if (param->board.map[param->player.x][param->player.y] == B_COLLECTABLE)
	{
		while (i < param->colect.starting)
		{
			if (&param->colect.set[i])
				if (param->colect.set[i].x == param->player.x && param->colect.set[i].y == param->player.y)
				{
					free(&param->colect.set[i]);
					param->colect.current--;
					break ;
				}
		}
	}
}

void	check_wall(t_params *param, char dir)
{
	if (param->board.map[param->player.x][param->player.y] == B_WALL)
	{
		param->player.x = param->player.x - (dir == 's') + (dir == 'n');
		param->player.y = param->player.y + (dir == 'e') - (dir == 'w');
	}
	else
		param->moves++;
}

void go_dir(void *param_raw, char dir)
{
	t_params *param;

	param = param_raw;
	ft_printf("\ndir: %c pre %i %i", dir, param->player.x, param->player.y);

	ft_printf(" - %i %i %i %i - ", dir == 'n', dir == 's', dir == 'e', dir == 'w');
	
	param->player.y = param->player.y + (dir == 's') - (dir == 'n');
	param->player.x = param->player.x + (dir == 'e') - (dir == 'w');
	
	ft_printf("\tnext %i %i", param->player.x, param->player.y);

//	check_wall(param, dir);
//	check_collect(param);
//	print_display(param);
//	ft_printf("\tend %i %i", param->player.x, param->player.y);
}