/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:59:46 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/21 19:43:51 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniLibX.h"


int expose_funct(void *param_raw)
{
	t_params *param;

	param = param_raw;
	print_display(param);
	return (0);
}

int keyboard_events(int keycode, void *param_raw)
{
	t_params *param;

	param = param_raw;
	
	if (keycode == XK_Escape)
		close_window(param);
	else if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		go_dir(param, 'n');
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		go_dir(param, 'e');
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		go_dir(param, 'w');
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		go_dir(param, 's');
	return (0);
}