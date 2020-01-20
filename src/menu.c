/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:52:59 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 12:30:31 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../include/colors.h"
#include <stdlib.h>

int		check_for_button(t_lst_display *win, int x, int y)
{
	int i;

	i = 0;
	while (i < BUT_NB)
	{
		if ((x > (BUT_NB * i + 5 * i + 15)
		&& x < (i * BUTTON_WIDTH + BUTTON_WIDTH + 5 * i + 15))
		&& (y > 140 + DISPLAY_HEIGHT
		&& y < 140 + DISPLAY_HEIGHT + BUTTON_HEIGHT))
		{
			win->button_lst[i].pt_function_init(win);
			return (1);
		}
		i++;
	}
	return (0);
}

void	draw_button(t_lst_display *w, t_button *butt)
{
	int x;
	int y;

	y = 0;
	while (y < BUTTON_HEIGHT)
	{
		x = 0;
		while (x < BUTTON_WIDTH)
		{
			fill_pix_ui(w, x + butt->x, y + butt->y, 0x778899);
			x++;
		}
		y++;
	}
}

void	draw_buttons(t_lst_display *w)
{
	int i;

	i = 0;
	while (i < BUT_NB)
	{
		draw_button(w, &w->button_lst[i]);
		i++;
	}
}

void	create_button(t_button *butt, int x, int y, void *function)
{
	butt->x = x;
	butt->y = y;
	butt->pt_function_init = function;
}

int		initialise_button_lst(t_lst_display *win)
{
	if (!(win->button_lst = (t_button *)malloc((sizeof(t_button)) * BUT_NB)))
		return (0);
	create_button(&(win->button_lst[0]), 15, 140,
	(t_lst_display *)&ini_fractal_mandel);
	create_button(&(win->button_lst[1]), 85, 140,
	(t_lst_display *)&ini_fractal_julia);
	create_button(&(win->button_lst[2]), 155, 140,
	(t_lst_display *)&ini_fractal_tricorn);
	create_button(&(win->button_lst[3]), 225, 140,
	(t_lst_display *)&ini_fractal_burningship);
	create_button(&(win->button_lst[4]), 295, 140,
	(t_lst_display *)&ini_fractal_mandel3);
	create_button(&(win->button_lst[5]), 365, 140,
	(t_lst_display *)&ini_fractal_julia3);
	create_button(&(win->button_lst[6]), 435, 140,
	(t_lst_display *)&ini_fractal_phoenix);
	create_button(&(win->button_lst[7]), 505, 140,
	(t_lst_display *)&ini_fractal_feigen);
	create_button(&(win->button_lst[8]), 575, 140,
	(t_lst_display *)&ini_fractal_heart);
	create_button(&(win->button_lst[9]), 645, 140,
	(t_lst_display *)&ini_fractal_hazard);
	create_button(&(win->button_lst[10]), 715, 140,
	(t_lst_display *)&ini_fractal_pines);
	return (1);
}
