/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:02:52 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/14 16:51:18 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/colors.h"
// a retirer
#include <stdio.h>


unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b)
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
void set_color_to_mode1(t_lst_display **win)
{
	/*
	(*win)->palette[0] = BROWN_3;
	(*win)->palette[1] = DARK_VIOLET;
	(*win)->palette[2] = DARKEST_BLUE;
	(*win)->palette[3] =  BLUE_5;
	(*win)->palette[4] = BLUE_4;
	(*win)->palette[5] = BLUE_3;
	(*win)->palette[6] = BLUE_2;
	(*win)->palette[7] = BLUE_1;
	(*win)->palette[8] = BLUE_0;
	(*win)->palette[9] = BLUE_LIGHTEST; 
	(*win)->palette[10] = YELLOW_LIGHTEST; 
	(*win)->palette[11] = LIGHT_YELLOW; 
	(*win)->palette[12] = DIRTY_YELLOW;
	(*win)->palette[13] = BROWN_0;
	(*win)->palette[14] = BROWN_1;
	(*win)->palette[15] = BROWN_2;
	*/
	/*
	(*win)->palette[0] = convert_rgb(0x0, 254, 0,0); // Red Neon
	(*win)->palette[1] = convert_rgb(0x0, 253, 254,2); // yellow neon
	(*win)->palette[2] = convert_rgb(0x0, 11, 255,1); // green non
	(*win)->palette[3] = convert_rgb(0x0, 1, 30,254); // blue neon
	(*win)->palette[4] = convert_rgb(0x0, 254, 0,246); // pink neon
	(*win)->palette[5] = BLUE_3;
	(*win)->palette[6] = BLUE_2;
	(*win)->palette[7] = BLUE_1;
	(*win)->palette[8] = BLUE_0;
	(*win)->palette[9] = BLUE_LIGHTEST; 
	(*win)->palette[10] = YELLOW_LIGHTEST; 
	(*win)->palette[11] = LIGHT_YELLOW; 
	(*win)->palette[12] = DIRTY_YELLOW;
	(*win)->palette[13] = BROWN_0;
	(*win)->palette[14] = BROWN_1;
	(*win)->palette[15] = BROWN_2;
	*/
	(*win)->palette[0] = 0xFF0000;
	(*win)->palette[1] = 0xFF8000; // yellow neon
	(*win)->palette[2] = 0xFFFF00; //
	(*win)->palette[3] = 0x80FF00; //
	(*win)->palette[4] = 0x00FF00; //
	(*win)->palette[5] = 0x00FF80; //
	(*win)->palette[6] = 0x00FFFF; 
	(*win)->palette[7] = 0x0080FF; 
	(*win)->palette[8] = 0x0000FF; 
	(*win)->palette[9] = 0x7F00FF; 
	(*win)->palette[10] = 0xFF00FF; 
	(*win)->palette[11] = 0xFF007F; 
	(*win)->palette[12] = DIRTY_YELLOW;
	(*win)->palette[13] = BROWN_0;
	(*win)->palette[14] = BROWN_1;
	(*win)->palette[15] = BROWN_2;
}

unsigned int colormod (int n, t_lst_display **win)
{
	int i;
	double r;
	
	if ((*win)->color_mod == 1)
	{
	if (n < (*win)->Max_it && n > 0) {
 		i = n % 10;

    	return (*win)->palette[i];
		}
	}
	else if ((*win)->color_mod == 2)
	{	
		r = n / (*win)->Max_it;
		if (r == 1.0)
			return (convert_rgb(0x0, 255 * r, 0,0));

	}
	else if ((*win)->color_mod == 3)
	{	
		r = (double)n / (double)(*win)->Max_it;
		if (r == 1.0)
			return (convert_rgb(0x0, 0, 0,0));
		if (r > 0.5)
			return (convert_rgb(0x0, 255 * r, 255,255 * r));
		else
			return (convert_rgb(0x0, 0, 255 * r, 0));
	}
	
	return (convert_rgb(0x0, 0, 0,0));
}