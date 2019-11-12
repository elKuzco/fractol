/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:42:02 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/06 17:05:41 by qlouisia         ###   ########.fr       */
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
	(*win)->w_width = 800;
	(*win)->w_height = 800;
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, (*win)->w_width,(*win)->w_height, tittle);
	(*win)->img_ptr = mlx_new_image(mlx_serv,(*win)->w_width,(*win)->w_height);
	(*win)->data = (int *)mlx_get_data_addr((*win)->img_ptr,&(*win)->bpp,&(*win)->size_l,&(*win)->endian);
	(*win)->zoom_scale = 100; // previously 1
	(*win)->x = (*win)->w_width / 2;
	(*win)->y = (*win)->w_height / 2;
	return(1);
}

