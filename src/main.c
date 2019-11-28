/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/28 14:02:54 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"

int	get_input(int keycode, t_lst_display *win)
{
	if (keycode == 53)
		return (quit_program(win));
	if (keycode > 122 && keycode < 127)
		move(keycode, win);
	if (keycode > 14 && keycode < 79)
		change_fractal(keycode, win);
	refresh_image(win);
	return (0);
}

int	print_usage(void)
{
	ft_putendl("Incorrect Usage :");
	ft_putstr("./fractol + mandelbrot / julia /");
	ft_putendl(" tricorn / burningship / mandelbrot3 / julia3");
	return (0);
}

int	select_fractal(t_lst_display *win, char *input)
{
	if (!ft_strcmp(input, "mandelbrot"))
		win->pt_function_init = &initialise_fractal_mandel;
	else if (!ft_strcmp(input, "julia"))
		win->pt_function_init = &initialise_fractal_julia;
	else if (!ft_strcmp(input, "tricorn"))
		win->pt_function_init = &initialise_fractal_tricorn;
	else if (!ft_strcmp(input, "burningship"))
		win->pt_function_init = &initialise_fractal_burningship;
	else if (!ft_strcmp(input, "mandelbrot3"))
		win->pt_function_init = &initialise_fractal_mandel3;
	else if (!ft_strcmp(input, "julia3"))
		win->pt_function_init = &initialise_fractal_julia3;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_lst_display	win;
	void			*mlx_serv;

	mlx_serv = mlx_init();
	(void)argv;
	if (argc < 2 || argc > 3 || !(initialise_graphic(&win, mlx_serv, argv[1])))
		return (print_usage());
	if (!select_fractal(&win, argv[1]))
		return (print_usage());
	win.pt_function_init(&win);
	display(mlx_serv, &win);
}
