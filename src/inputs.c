/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:20:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/12 17:13:29 by qlouisia         ###   ########.fr       */
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
	double tmp;
	
	//(*win)->x = 0.3;
	if (m_code == 1)
	{
	tmp = ((*win)->Maxreal  - x) * (*win)->Real_scale;
	//tmp = ( x - (*win)->w_width /(*win)->Maxreal - (*win)->Minreal) * (*win)->Real_scale;
	//tmp = x * (*win)->Real_scale;
	printf("tmp :%f \n",tmp);
	(*win)->Minreal += tmp; 
	(*win)->Maxreal += tmp; 
	tmp = ((*win)->Maxima  - y) * (*win)->Ima_scale;
	//tmp = ( y - (*win)->w_height /(*win)->Maxima - (*win)->Minima) * (*win)->Ima_scale;
	//tmp = y * (*win)->Ima_scale;
	(*win)->Minima+= tmp;
	(*win)->Maxima = (*win)->Minima +((*win)->Maxreal - (*win)->Minreal) * ((*win)->w_height / (*win)->w_width); 
	(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->w_width; // (*win)->w_width - 1
	(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->w_height; // (*win)->w_height - 1
	
	printf("minreal :%f | Max_real :%f\n",(*win)->Minreal,(*win)->Maxreal );
	printf("minima :%f | Max_ima :%f\n",(*win)->Minima,(*win)->Maxima);
	printf("Real_scale :%f | Ima_scale :%f\n",(*win)->Real_scale,(*win)->Ima_scale);
	}
	if (m_code == 5)
	{
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