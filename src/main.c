/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/10/23 17:23:26 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"



int		expose_hook(t_lst_display **win)
{
	refresh_image(win);
	return (1);
}

void display(void *ser, t_lst_display **win)
{
	initialise_fractal_mandel(win);
	(*win)->pt_function(win);
	mlx_expose_hook((*win)->win_ptr, expose_hook, win);
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
		
	display(mlx_serv, &win);
}