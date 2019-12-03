/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:42:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/03 12:20:45 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include "mlx.h"

int	initialise_graphic(t_lst_display *w, void *mlx_serv, char *tittle)
{
	ft_bzero(w, sizeof(t_lst_display));
	w->mlx_ptr = mlx_serv;
	w->display_w = DISPLAY_WIDTH;
	w->display_h = DISPLAY_HEIGHT;
	w->win_ptr = mlx_new_window(w->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
	tittle);
	w->display_img_ptr = mlx_new_image(mlx_serv, w->display_w, w->display_h);
	w->data_display = (int *)mlx_get_data_addr(w->display_img_ptr, &w->bpp,
	&w->size_l, &w->endian);
	w->ui_img_ptr = mlx_new_image(mlx_serv, WINDOW_WIDTH,
	WINDOW_HEIGHT - DISPLAY_HEIGHT);
	w->data_ui = (int *)mlx_get_data_addr(w->ui_img_ptr, &w->bpp,
	&w->size_l, &w->endian);
	w->zoom_scale = 250;
	w->clr_m = 1;
	w->Max_it = 60;
	initialise_button_lst(w);
	return (1);
}

