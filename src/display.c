/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:51:27 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/04 12:39:32 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include <stdlib.h>

void	print_ui(t_lst_display **env)
{
	char *rotz;
	char *rotx;
	char *roty;

	rotz = ft_itoa((*env)->zoom_scale);
	roty = ft_itoa((*env)->Minima);
	rotx = ft_itoa((*env)->Maxreal);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 10, 255255255, "Zoom:");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 120, 10, 255255255, rotz);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 30, 255255255, "Min ima :");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 120, 30, 255255255, rotx);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 50, 255255255, "Max real:");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 120, 50, 255255255, roty);

	free(rotz);
	free(rotx);
	free(roty);
}

void	refresh_image(t_lst_display **win)
{
	int i;
	int n;

	n = (*win)->w_width * (*win)->w_height;
	i = 0;
	while (i < n)
	{
		(*win)->data[i] = 0;
		i++;
	}
	
	(*win)->pt_function(win);
	mlx_clear_window((*win)->mlx_ptr, (*win)->win_ptr);
	mlx_put_image_to_window((*win)->mlx_ptr, (*win)->win_ptr,
	(*win)->img_ptr, 0, 0);
	//print_ui(win);

}

void	fill_pix(t_lst_display **img, int x, int y, int color)
{
	if ((x < (*img)->w_width) && (x >= 0)
		&& (y < (*img)->w_height) && (y >= 0))
	{
		(*img)->data[y * (*img)->w_width + x] = color;
	}
}

