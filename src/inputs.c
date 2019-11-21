/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/19 15:03:27 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fractol.h"
#include "mlx.h"

#include <stdio.h>
int quit_program(t_lst_display *env)
{
	if (env->win_ptr)
	{
		mlx_destroy_image(env->mlx_ptr, env->display_img_ptr);
		mlx_destroy_image(env->mlx_ptr, env->ui_img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
}


int mouse_control(int m_code, int x, int y, t_lst_display *win)
{
	double tmp_zoom;
	tmp_zoom = win->zoom_scale;
	if (x < DISPLAY_WIDTH && y < DISPLAY_HEIGHT)
	{
		if (m_code == 5)
		{
			win->zoom_scale *= 1.1;
			win->Max_it++;
		}
		if (m_code == 4 && (win->zoom_scale > 1))
		{
			win->zoom_scale /= 1.1;
			win->Max_it--;
		}
		win->Minreal += (x / tmp_zoom) - ( x / win->zoom_scale);
		win->Minima += (y / tmp_zoom) - ( y / win->zoom_scale);
		win->Real_scale = (win->Maxreal - win->Minreal) / win->display_w; 
		win->Ima_scale = (win->Maxima - win->Minima) / win->display_h;
		refresh_image(win);
	}
	return (0);
}

/*
**              #######################################
**              ################# Move ################
**              #######################################
**
** Get the input and change the value of position of the object
** Keycode 124 = 'Arrow  right'
** Keycode 123 = 'Arrow  left'
** Keycode 125 = 'Arrow  down'
** Keycode 126 = 'Arrow  up'
*/

 int motion_hook(int x, int y, t_lst_display *win)
 {
	 	if (win->julia_mod_enable == true)
		{
			win->julia_re = x / win->zoom_scale + win->Minreal;
			win->julia_im = y / win->zoom_scale + win->Minima;

		} 
		refresh_image(win);
		return(0);
 }

int	move(int keycode, t_lst_display *param)
{
	printf("keycode : %d\n", keycode);
	if (keycode == 124)
		param->Minreal += 8/ param->zoom_scale ;
	if (keycode == 123)
		param->Minreal -= 8/ param->zoom_scale ;
	if (keycode == 125)
		param->Minima -= 8/ param->zoom_scale ;
	if (keycode == 126)
		param->Minima += 8/ param->zoom_scale ;
	if (keycode == 18)
		param->color_mod = 2;
	if (keycode == 19){
		param->color_mod = 1;
		set_color_to_mode1(param);
	}
	if (keycode == 20)
		param->color_mod = 3;
	if (keycode == 21)
	{
		set_color_to_rainbow(param);
		param->color_mod = 4;
	}
	if (keycode == 53)
		quit_program(param);
	if (keycode == 15)
	{
	param->Minreal = -2.0;
	param->Minima = -1.2;
	param->Maxreal = 1.0;
	param->Maxima = param->Minima +(param->Maxreal - param->Minreal) * (param->display_h / param->display_w); 
	param->Real_scale = (param->Maxreal - param->Minreal) / param->display_w; 
	param->Ima_scale = (param->Maxima - param->Minima) / param->display_h; 
	param->Max_it = 60;
	param->zoom_scale = 250;
	}
	if (keycode == 16)
	{
		if (param->julia_mod_enable == false)
			param->julia_mod_enable = true;
		else 
			param->julia_mod_enable = false;
	}
	if (keycode == 69)
	{
		if (param->Max_it < 1000)
			param->Max_it += 5;
	}
	if (keycode == 78)
	{
		if (param->Max_it > 10)
			param->Max_it -= 5;
	}
	refresh_image(param);
	return (0);
}