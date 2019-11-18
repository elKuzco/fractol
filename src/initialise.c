/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:42:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/18 19:34:18 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include "mlx.h"


int initialise_graphic(t_lst_display **win, void *mlx_serv, char *tittle)
{
	if (!(*win = (t_lst_display*)malloc(sizeof(t_lst_display))))
		return (0);
	

	(*win)->mlx_ptr = mlx_serv;
	(*win)->display_w = DISPLAY_WIDTH;
	(*win)->display_h = DISPLAY_HEIGHT;
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT, tittle);
	(*win)->img_ptr = mlx_new_image(mlx_serv,(*win)->display_w,(*win)->display_h);
	(*win)->data = (int *)mlx_get_data_addr((*win)->img_ptr,&(*win)->bpp,&(*win)->size_l,&(*win)->endian);
	(*win)->zoom_scale = 100; // previously 1
	return(1);
}


