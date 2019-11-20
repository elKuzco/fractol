/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:42:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/19 17:41:18 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include "mlx.h"


int initialise_graphic(t_lst_display *win, void *mlx_serv, char *tittle)
{
	ft_bzero(win,sizeof(t_lst_display));
	win->mlx_ptr = mlx_serv;
	win->display_w = DISPLAY_WIDTH;
	win->display_h = DISPLAY_HEIGHT;
	win->win_ptr = mlx_new_window(win->mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT, tittle);
	win->display_img_ptr = mlx_new_image(mlx_serv,win->display_w,win->display_h);
	win->data_display = (int *)mlx_get_data_addr(win->display_img_ptr,&win->bpp,&win->size_l,&win->endian);
	win->ui_img_ptr = mlx_new_image(mlx_serv,WINDOW_WIDTH ,WINDOW_HEIGHT - DISPLAY_HEIGHT);
	win->data_ui = (int *)mlx_get_data_addr(win->ui_img_ptr,&win->bpp,&win->size_l,&win->endian);
	win->zoom_scale = 250;
	win->color_mod = 1;
	win->Max_it = 60;
	return(1);
}


