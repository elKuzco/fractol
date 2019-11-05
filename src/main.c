/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/04 12:08:06 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
// a retirer
#include <stdio.h>

int		get_input(int keycode, t_lst_display **win)
{
	printf("Key :%d",keycode);
	if (keycode == 69)
	{
			(*win)->Minreal += (*win)->zoom_scale;
			(*win)->Minima += (*win)->zoom_scale;
			(*win)->Maxreal -= (*win)->zoom_scale;
			(*win)->Maxima = (*win)->Minima +((*win)->Maxreal - (*win)->Minreal) * ((*win)->w_height / (*win)->w_width); 
			(*win)->Real_scale = ((*win)->Maxreal - (*win)->Minreal) / (*win)->w_width; // (*win)->w_width - 1
			(*win)->Ima_scale = ((*win)->Maxima - (*win)->Minima) / (*win)->w_height; // (*win)->w_height - 1
			//(*win)->Max_it += 1;

	//int a = (*param)->Minima;
	//a = 0;
	}
	refresh_image(win);
	return(0);
}

int		expose_hook(t_lst_display **win)
{
	refresh_image(win);
	return (1);
}

void display(void *ser, t_lst_display **win)
{
	(*win)->pt_function(win);
	mlx_expose_hook((*win)->win_ptr, expose_hook, win);
	mlx_hook((*win)->win_ptr, 17, 1L << 17, quit_program, win);
	mlx_mouse_hook((*win)->win_ptr,mouse_control,win);
//	mlx_hook((*win)->win_ptr, 6, 1L < 6, get_input, win); // 4, 0
	mlx_loop(ser);
}

int main(int argc, char **argv)
{
	t_lst_display *win;
	void *mlx_serv;
	
	
	mlx_serv = mlx_init();
	(void)argv;
	
	if (argc < 2 || argc >3 || !(initialise_graphic(&win, mlx_serv, argv[1])))
		return (0);
	initialise_fractal_mandel(&win);	
	display(mlx_serv, &win);
}