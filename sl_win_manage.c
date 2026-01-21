/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_win_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:59:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/21 19:20:04 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniLibX.h"


void	print_display(void *param_raw)
{
	t_params *param;

	param = param_raw;
	mlx_put_image_to_window(param->mlx, param->win, param->main_img, 0, 0);
}

void close_window(void *param_raw)
{
	t_params *param;

	param = param_raw;
	mlx_destroy_window(param->mlx, param->win);
	exit(1);
}