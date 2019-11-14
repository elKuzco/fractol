/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/14 15:49:45 by qlouisia         ###   ########.fr       */
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

	/*
	if (m_code == 1)
	{

}*/
	if (m_code == 5)
	{
		double tmp_zoom;
		tmp_zoom = (*win)->zoom_scale;
		(*win)->zoom_scale *= 1.1;
		(*win)->Minreal += (x / tmp_zoom) - ( x / (*win)->zoom_scale);
		(*win)->Minima += (y / tmp_zoom) - ( y / (*win)->zoom_scale);
		(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->w_width; // (*win)->w_width - 1
		(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->w_height; // (*win)->w_height - 1
		//(*win)->Max_it += 5;
		/*
		(*win)->x = x - ( x - (*win)->w_width /2) * 1.1;
		(*win)->y = y - ( y - (*win)->w_height /2) * 1.1;
		printf("x :%f | y :%f\n",(*win)->x,(*win)->y );
		(*win)->zoom_scale *= 1.1;
		(*win)->Max_it += 3;
		printf("Zoom :%f\n",(*win)->zoom_scale);*/
	}
	if (m_code == 4 && ((*win)->zoom_scale > 1))
	{
		double tmp_zoom;
		tmp_zoom = (*win)->zoom_scale;
		(*win)->zoom_scale /= 1.1;
		(*win)->Minreal += (x / tmp_zoom) - ( x / (*win)->zoom_scale);
		(*win)->Minima += (y / tmp_zoom) - ( y / (*win)->zoom_scale);
		(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->w_width; // (*win)->w_width - 1
		(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->w_height; // (*win)->w_height - 1
		/*
		(*win)->x = x - ( x - (*win)->w_width/2) / 1.1;
		(*win)->y = y - ( y - (*win)->w_height/2) / 1.1;
		printf("x :%f | y :%f\n",(*win)->x,(*win)->y );
		(*win)->zoom_scale /= 1.1;
		(*win)->Max_it -= 3;
		printf("Zoom :%f\n",(*win)->zoom_scale);*/
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
	if (keycode == 13)
		(*param)->color_mod = 1;
	if (keycode == 14)
		(*param)->color_mod = 3;
	refresh_image(param);
	return (0);
}