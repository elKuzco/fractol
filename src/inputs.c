/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 13:30:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fractol.h"
#include "mlx.h"

int		quit_program(t_lst_display *env)
{
	if (env->win_ptr)
	{
		mlx_destroy_image(env->mlx_ptr, env->display_img_ptr);
		mlx_destroy_image(env->mlx_ptr, env->ui_img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		free(env->button_lst);
	}
	exit(0);
}

int		mouse_control(int m_code, int x, int y, t_lst_display *win)
{
	double tmp_zoom;

	tmp_zoom = win->zoom_scale;
	if (x < DISPLAY_WIDTH && y < DISPLAY_HEIGHT)
	{
		if (m_code == 5)
		{
			win->zoom_scale *= 1.1;
			win->max_it++;
		}
		if (m_code == 4 && (win->zoom_scale > 1))
		{
			win->zoom_scale /= 1.1;
			if (win->max_it > 10)
				win->max_it--;
		}
		win->minreal += (x / tmp_zoom) - (x / win->zoom_scale);
		win->minima += (y / tmp_zoom) - (y / win->zoom_scale);
		win->real_scale = (win->maxreal - win->minreal) / win->display_w;
		win->ima_scale = (win->maxima - win->minima) / win->display_h;
		refresh_image(win);
	}
	else if (m_code == 1)
		check_for_button(win, x, y);
	return (0);
}

int		motion_hook(int x, int y, t_lst_display *win)
{
	if (win->julia_mod_enable == true)
	{
		win->julia_re = x / win->zoom_scale + win->minreal;
		win->julia_im = y / win->zoom_scale + win->minima;
	}
	refresh_image(win);
	return (0);
}

void	change_fractal(int keycode, t_lst_display *p)
{
	(keycode == 18) ? p->clr_m = 2 : 0;
	if (keycode == 19)
	{
		p->clr_m = 1;
		set_color_to_mode1(p);
	}
	(keycode == 20) ? p->clr_m = 3 : 0;
	if (keycode == 21)
	{
		set_color_to_rainbow(p);
		p->clr_m = 4;
	}
	(keycode == 15) ? p->pt_function_init(p) : 0;
	if (keycode == 16)
		p->julia_mod_enable = (p->julia_mod_enable == false) ? true : false;
	if (keycode == 69)
		p->max_it += (p->max_it < 1000) ? 2 : 0;
	if (keycode == 78)
		p->max_it -= (p->max_it > 10) ? 2 : 0;
	refresh_image(p);
}

int		move(int keycode, t_lst_display *param)
{
	if (keycode == 124)
		param->minreal += 8 / param->zoom_scale;
	if (keycode == 123)
		param->minreal -= 8 / param->zoom_scale;
	if (keycode == 125)
		param->minima -= 8 / param->zoom_scale;
	if (keycode == 126)
		param->minima += 8 / param->zoom_scale;
	return (0);
}
