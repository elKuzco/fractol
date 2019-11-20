/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:51:27 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/19 17:40:51 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../include/colors.h"
#include <stdlib.h>


// a delet
#include <stdio.h>


void	fill_pix(t_lst_display *img, int x, int y, int color)
{
	if ((x < img->display_w) && (x >= 0)
		&& (y < img->display_h) && (y >= 0))
	{
		img->data_display[y * img->display_w + x] = color;
	}
}

void	fill_pix_ui(t_lst_display *img, int x, int y, int color)
{
	if ((x < WINDOW_WIDTH) && (x >= 0)
		&& (y < WINDOW_HEIGHT) && (y >= 0))
	{
		img->data_ui[y * WINDOW_WIDTH+ x] = color;
	}
}

void draw_background(t_lst_display *win, int y, int x, unsigned int color)
{
	y = 0;
	while (y < WINDOW_HEIGHT - DISPLAY_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			fill_pix_ui(win,x,y,color);
			x++;
		}
		y++;
	}
}

void print_command(t_lst_display *win) 
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 330, 950, GREEN_UI, "Instructions :");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 330, 955, GREEN_UI, "____________");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 30, 1000, GREEN_UI, "Zoom : Wheel");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 30, 1020, GREEN_UI, "Mouse : Arrow");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 30, 1040, GREEN_UI, "Change Color : 1/2/3/4");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 30, 1060, GREEN_UI, "Reset : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 30, 1080, GREEN_UI, "Julia modification : Y");
}

void	print_ui(t_lst_display *env)
{
	char *iter;
	char *color;
	char *zoom;
	
	if (env->color_mod == 2)
		color = "Blood Strain";
	else if (env->color_mod == 1)
		color = "Polarized";
	else if (env->color_mod == 3)
		color = "Matrix";
	else 
		color = "Rainbow";
	iter = ft_itoa(env->Max_it);
	zoom = ft_itoa(env->zoom_scale / 100);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 820, GREEN_UI, "Iteration Max: ");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 180, 820, GREEN_UI, iter);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 590, 820, GREEN_UI, "Color : ");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 665, 820, GREEN_UI, color);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 850, GREEN_UI, "Zoom : x");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 112, 850, GREEN_UI, zoom);
	if (env->julia_mod_enable == true)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 880, GREEN_UI, "Mode julia : On");
	else 
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 880, GREEN_UI, "Mode julia : Off");
	print_command(env); 
	free(iter);
	free(zoom);

}


void	refresh_image(t_lst_display *win)
{
	int i;
	int n;

	n = win->display_w * win->display_h;
	i = 0;
	while (i < n)
	{
		win->data_display[i] = 0;
		i++;
	}
	initialise_thread(win);
	//mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
	win->display_img_ptr, 0, 0);
	draw_background((win), win->display_h, 0, GREY_UI);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
	win->ui_img_ptr,0, DISPLAY_HEIGHT );
	print_ui(win);

}