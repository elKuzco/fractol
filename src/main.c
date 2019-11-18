/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/15 11:48:17 by qlouisia         ###   ########.fr       */
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
	if (keycode == 124)
	{
		(*win)->Minreal += 3/ (*win)->zoom_scale ;
		printf("arrow right");
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
	//mlx_expose_hook((*win)->win_ptr, expose_hook, win);
	mlx_hook((*win)->win_ptr, 17, 1L << 17, quit_program, win);
	mlx_hook((*win)->win_ptr, 2, 3, move, win);
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