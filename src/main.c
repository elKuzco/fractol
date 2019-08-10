/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:34:21 by qlouisia          #+#    #+#             */
/*   Updated: 2019/08/10 15:15:24 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"


void display(void *ser)
{
	mlx_loop(ser);
}

int main(int argc, char **argv)
{
	t_lst_display *win;
	void *mlx_serv;
	
	
	mlx_serv = mlx_init();
	(void)argv;
	
	if (argc < 2 || argc >3 || !(initialise_graphic(&win, mlx_serv, "fenetre")))
		return (0);
		
	display(mlx_serv);
}