/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/18 13:05:46 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fractol.h"
#include "mlx.h"

#include <stdio.h>
int quit_program(t_lst_display **env)
{
	if ((*env)->win_ptr)
	{
		mlx_destroy_image((*env)->mlx_ptr, (*env)->img_ptr);
		mlx_destroy_window((*env)->mlx_ptr, (*env)->win_ptr);
	}
	free(*env);
	exit(0);
}


int mouse_control(int m_code, int x, int y, t_lst_display **win)
{

	if (m_code == 5)
	{
		double tmp_zoom;
		tmp_zoom = (*win)->zoom_scale;
		(*win)->zoom_scale *= 1.1;
		(*win)->Minreal += (x / tmp_zoom) - ( x / (*win)->zoom_scale);
		(*win)->Minima += (y / tmp_zoom) - ( y / (*win)->zoom_scale);
		(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->display_w; // (*win)->display_w - 1
		(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->display_h; // (*win)->display_h - 1
		if ((*win)->Max_it++ < 120)
			(*win)->Max_it++;
		else 
			(*win)->Max_it = 60;
	}
	if (m_code == 4 && ((*win)->zoom_scale > 1))
	{
		double tmp_zoom;
		tmp_zoom = (*win)->zoom_scale;
		(*win)->zoom_scale /= 1.1;
		(*win)->Minreal += (x / tmp_zoom) - ( x / (*win)->zoom_scale);
		(*win)->Minima += (y / tmp_zoom) - ( y / (*win)->zoom_scale);
		(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->display_w; // (*win)->display_w - 1
		(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->display_h; // (*win)->display_h - 1
		if ((*win)->Max_it > 65)
			(*win)->Max_it--;
	}
	
	refresh_image(win);
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

int	move(int keycode, t_lst_display **param)
{
	if (keycode == 124)
		(*param)->Minreal += 8/ (*param)->zoom_scale ;
	if (keycode == 123)
		(*param)->Minreal -= 8/ (*param)->zoom_scale ;
	if (keycode == 125)
		(*param)->Minima -= 8/ (*param)->zoom_scale ;
	if (keycode == 126)
		(*param)->Minima += 8/ (*param)->zoom_scale ;
	if (keycode == 12)
		(*param)->color_mod = 2;
	if (keycode == 13){
		(*param)->color_mod = 1;
		set_color_to_mode1(param);
	}
	if (keycode == 14)
		(*param)->color_mod = 3;
	if (keycode == 15)
	{
		set_color_to_rainbow(param);
		(*param)->color_mod = 4;
	}
	if (keycode == 69)
	{
		if ((*param)->Max_it < 300)
			(*param)->Max_it += 5;
	}
	if (keycode == 78)
	{
		if ((*param)->Max_it > 10)
			(*param)->Max_it -= 5;
	}
	refresh_image(param);
	return (0);
}