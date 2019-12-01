/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:22:59 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/01 14:34:28 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../include/colors.h"
#include <stdlib.h>

void	fill_pix_ui(t_lst_display *img, int x, int y, int color)
{
	if ((x < WINDOW_WIDTH) && (x >= 0)
		&& (y < WINDOW_HEIGHT) && (y >= 0))
	{
		img->data_ui[y * WINDOW_WIDTH + x] = color;
	}
}

void	draw_background(t_lst_display *win, int y, int x, unsigned int color)
{
	y = 0;
	while (y < WINDOW_HEIGHT - DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			fill_pix_ui(win, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_command(t_lst_display *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 330, 1010, G_UI, "Instructions :");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 330, 1015, G_UI, "____________");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 30, 1060, G_UI, "Zoom : Wheel");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 30, 1080, G_UI, "Mouse : Arrow");
	mlx_string_put(w->mlx_ptr, w->win_ptr,
	30, 1040, G_UI, "Change Color : 1/2/3/4");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 30, 1120, G_UI, "Reset : R");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 30, 1140, G_UI, "Change Julia : Y");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 30, 1160, G_UI,
	"Change resolution : +/-");
}

void	check_zoom(t_lst_display *e)
{
	char	*zoom;

	if (e->zoom_scale < INTMAX)
	{
		zoom = ft_itoa(e->zoom_scale / 100);
		mlx_string_put(e->mlx_ptr, e->win_ptr, 30, 850, G_UI, "Zoom : x");
		mlx_string_put(e->mlx_ptr, e->win_ptr, 112, 850, G_UI, zoom);
		free(zoom);
	}
	else
	{
		mlx_string_put(e->mlx_ptr, e->win_ptr, 30, 850,
		G_UI, "Zoom : Too Long");
	}
}

void	print_ui(t_lst_display *e)
{
	char *iter;
	char *color;

	(e->clr_m == 2) ? color = "Blood Strain" : 0;
	(e->clr_m == 1) ? color = "Polarized" : 0;
	(e->clr_m == 3) ? color = "Matrix" : 0;
	(e->clr_m == 4) ? color = "Rainbow" : 0;
	iter = ft_itoa(e->Max_it);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 30, 820, G_UI, "Iteration Max:");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 180, 820, G_UI, iter);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 590, 820, G_UI, "Color :");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 665, 820, G_UI, color);
	check_zoom(e);
	if (e->julia_mod_enable == true)
		mlx_string_put(e->mlx_ptr, e->win_ptr, 30, 880, G_UI, "Mod julia: On");
	else
		mlx_string_put(e->mlx_ptr, e->win_ptr, 30, 880, G_UI, "Mod julia: Off");
	print_command(e);
	free(iter);
}
