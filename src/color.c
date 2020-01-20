/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:02:52 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 13:30:15 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/colors.h"

unsigned int	convert_rgb(unsigned int a, unsigned int r,
				unsigned int g, unsigned int b)
{
	unsigned int nb;

	if (a > 0xff)
		a = 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	return (nb);
}

void			set_color_to_mode1(t_lst_display *win)
{
	win->palette[0] = BROWN_3;
	win->palette[1] = DARK_VIOLET;
	win->palette[2] = DARKEST_BLUE;
	win->palette[3] = BLUE_5;
	win->palette[4] = BLUE_4;
	win->palette[5] = BLUE_3;
	win->palette[6] = BLUE_2;
	win->palette[7] = BLUE_1;
	win->palette[8] = BLUE_0;
	win->palette[9] = BLUE_LIGHTEST;
	win->palette[10] = YELLOW_LIGHTEST;
	win->palette[11] = LIGHT_YELLOW;
	win->palette[12] = DIRTY_YELLOW;
	win->palette[13] = BROWN_0;
	win->palette[14] = BROWN_1;
	win->palette[15] = BROWN_2;
	win->palettte_size = 16;
}

void			set_color_to_rainbow(t_lst_display *win)
{
	win->palette[0] = NE_RED;
	win->palette[1] = NE_ORANGE;
	win->palette[2] = NE_YELLOW;
	win->palette[3] = NE_YGREEN;
	win->palette[4] = NE_GREEN;
	win->palette[5] = NE_BGREEN;
	win->palette[6] = NE_GBLUE;
	win->palette[7] = NE_BLUE;
	win->palette[8] = NE_PBLUE;
	win->palette[9] = NE_PURPLE;
	win->palette[10] = NE_PINK;
	win->palette[11] = NE_RPINK;
	win->palettte_size = 10;
}

unsigned int	colormod(int n, t_lst_display *win)
{
	int		i;
	double	r;

	if ((win->clr_m == 1 || win->clr_m == 4) && (n < win->max_it && n > 0))
	{
		i = n % win->palettte_size;
		return (win->palette[i]);
	}
	else if (win->clr_m == 2)
	{
		r = n / win->max_it;
		if (r == 1.0)
			return (convert_rgb(0x0, 255 * r, 0, 0));
	}
	else if (win->clr_m == 3)
	{
		r = (double)n / (double)win->max_it;
		if (r == 1.0)
			return (convert_rgb(0x0, 0, 0, 0));
		if (r > 0.5)
			return (convert_rgb(0x0, 255 * r, 255, 255 * r));
		else
			return (convert_rgb(0x0, 0, 255 * r, 0));
	}
	return (convert_rgb(0x0, 0, 0, 0));
}

void			color_wheel(t_lst_display *win)
{
	int	i;
	int	tmp;

	if ((win->clr_m == 1 || win->clr_m == 4))
	{
		i = 0;
		tmp = win->palette[0];
		while (i < win->palettte_size)
		{
			if (i == win->palettte_size - 1)
				win->palette[i] = tmp;
			else
				win->palette[i] = win->palette[i + 1];
			i++;
		}
	}
}
