/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/04 18:54:12 by qlouisia         ###   ########.fr       */
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
	printf("Key :%d\n",m_code);
	//printf("x :%d | y :%d\n",x,y);

	
	//(*win)->x = 0.3;
	if (m_code == 5)
	{
		(*win)->x = x - ( x - (*win)->w_width /2) * 1.1;
		(*win)->y = y - ( y - (*win)->w_height /2) * 1.1;
		printf("x :%f | y :%f\n",(*win)->x,(*win)->y );
		(*win)->zoom_scale *= 1.1;
		(*win)->Max_it += 3;
		printf("Zoom :%f\n",(*win)->zoom_scale);
	}
	if (m_code == 4 && ((*win)->zoom_scale > 1))
	{
		(*win)->x = x - ( x - (*win)->w_width/2) / 1.1;
		(*win)->y = y - ( y - (*win)->w_height/2) / 1.1;
		printf("x :%f | y :%f\n",(*win)->x,(*win)->y );
		(*win)->zoom_scale /= 1.1;
		(*win)->Max_it -= 3;
		printf("Zoom :%f\n",(*win)->zoom_scale);
	}
	
	refresh_image(win);
	return (0);
}