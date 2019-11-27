/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/27 12:39:42 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
// a retirer
// -g3 dans les makefile
#include <stdio.h>

int		get_input(int keycode, t_lst_display *win)
{
	printf("Key :%d",keycode);
	if (keycode == 124)
	{
		win->Minreal += 3/ win->zoom_scale ;
		printf("arrow right");
	//int a = param->Minima;
	//a = 0;
	}
	refresh_image(win);
	return(0);
}

int		expose_hook(t_lst_display *win)
{
	refresh_image(win);
	return (1);
}

void display(void *ser, t_lst_display *win)
{
	//win->pt_function(win);
	initialise_thread(win);
	//mlx_expose_hook(win->win_ptr, expose_hook, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, quit_program, win);
	mlx_hook(win->win_ptr, 2, 3, move, win);
	mlx_hook(win->win_ptr, 6, 0, motion_hook, win);
	mlx_mouse_hook(win->win_ptr,mouse_control,win);
	
//	mlx_hook(win->win_ptr, 6, 1L < 6, get_input, win); // 4, 0
	mlx_loop(ser);
}

int print_usage()
{
	ft_putendl("Incorrect Usage :");
	ft_putendl("./fractol + mandelbrot / julia / tricorn / burningship / mandelbrot3 / julia3");
	return (0);
}

int select_fractal(t_lst_display *win, char *input)
{
	if ( !ft_strcmp(input, "mandelbrot"))
		win->pt_function_init = &initialise_fractal_mandel;
	else if ( !ft_strcmp(input, "julia"))
		win->pt_function_init = &initialise_fractal_julia;
	else if ( !ft_strcmp(input, "tricorn"))
		win->pt_function_init = &initialise_fractal_tricorn;
	else if ( !ft_strcmp(input, "burningship"))
		win->pt_function_init = &initialise_fractal_burningship;
	else if ( !ft_strcmp(input, "mandelbrot3"))
		win->pt_function_init = &initialise_fractal_mandel3;
	else if ( !ft_strcmp(input, "julia3"))
		win->pt_function_init = &initialise_fractal_julia3;
	else 
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_lst_display win;
	void *mlx_serv;
	

	mlx_serv = mlx_init();
	(void)argv;
	
	if (argc < 2 || argc >3 || !(initialise_graphic(&win, mlx_serv, argv[1])))
		return (print_usage());
	if (!select_fractal(&win, argv[1]))
		return print_usage();
	win.pt_function_init(&win);
	display(mlx_serv, &win);
}