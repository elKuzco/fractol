/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:51:27 by qlouisia          #+#    #+#             */
/*   Updated: 2019/10/23 17:22:05 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"

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

}

void	fill_pix(t_lst_display **img, int x, int y, int color)
{
	if ((x < (*img)->w_width) && (x >= 0)
		&& (y < (*img)->w_height) && (y >= 0))
	{
		(*img)->data[y * (*img)->w_width + x] = color;
	}
}