/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:52:59 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/03 16:50:03 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../include/colors.h"
#include <stdlib.h>
// a retirer 
#include <stdio.h>
int     check_for_button(t_lst_display *win, int x, int y)
{
    int i;

    i = 0;
    while (i < BUTTON_NUMBER)
    {
        if ((x > (BUTTON_NUMBER  * i + 5 * i + 5) && x < (i * BUTTON_WIDTH + BUTTON_WIDTH + 5 * i + 5 )) && (y > 110 + DISPLAY_HEIGHT && y < 110 + DISPLAY_HEIGHT + BUTTON_HEIGHT))
        {
            win->button_lst[i].pt_function_init(win);
            return (1);
        }
        i++;
    }
    return (0);
}


void    draw_button(t_lst_display *w,t_button *butt)
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

void    draw_buttons(t_lst_display *w)
{
    int i;

    i = 0;
   while (i < BUTTON_NUMBER)
    {
        draw_button(w, &w->button_lst[i]);
        i++;
    }
}

void    create_button(t_button *butt, int x, int y,  char *str, void *function)
{
    void *tmp;
    butt->x = x;
    butt->y = y;
    butt->str = str;

    tmp = function;
    butt->pt_function_init = function;
}

int     initialise_button_lst(t_lst_display *win)
{
    if (!(win->button_lst = (t_button *)malloc((sizeof(t_button))* BUTTON_NUMBER)))
        return (0);
    create_button(&(win->button_lst[0]), 5 , 110, "mandelbrot",(t_lst_display *) &initialise_fractal_mandel);
    create_button(&(win->button_lst[1]), 75, 110, "Julia",(t_lst_display *) &initialise_fractal_julia);
    create_button(&(win->button_lst[2]), 145, 110, "Tricorn",(t_lst_display *) &initialise_fractal_tricorn);
    create_button(&(win->button_lst[3]), 215, 110, "ship",(t_lst_display *) &initialise_fractal_burningship);
    create_button(&(win->button_lst[4]), 285, 110, "Mandel3",(t_lst_display *) &initialise_fractal_mandel3);
    create_button(&(win->button_lst[5]), 355, 110, "Julia3",(t_lst_display *) &initialise_fractal_julia3);
    create_button(&(win->button_lst[6]), 425, 110, "phoenix",(t_lst_display *) &initialise_fractal_phoenix);
    create_button(&(win->button_lst[7]), 495, 110, "feigen",(t_lst_display *) &initialise_fractal_feigen);
    create_button(&(win->button_lst[8]), 565, 110, "Heart",(t_lst_display *) &initialise_fractal_heart);
    create_button(&(win->button_lst[9]), 635, 110, "Hazard",(t_lst_display *) &initialise_fractal_hazard);
    create_button(&(win->button_lst[10]), 705, 110, "Julia3",(t_lst_display *) &initialise_fractal_pines);
    return (1);
}

