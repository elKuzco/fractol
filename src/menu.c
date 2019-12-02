/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:52:59 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/02 19:51:39 by qlouisia         ###   ########.fr       */
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
        if ((x > (BUTTON_NUMBER  * i + 2 * i) && x < i * BUTTON_WIDTH + BUTTON_WIDTH + 2 * i ) && (y > 110 + DISPLAY_HEIGHT && y < 110 + DISPLAY_HEIGHT + BUTTON_HEIGHT))
    {
        printf("button : %d\n",i);
        initialise_fractal_julia(win);
        return (1);
    }
        i++;
    }
    return (0);
}

// void    load_fractal();

void    draw_button(t_lst_display *w,t_button *butt)
{
    int x;
    int y;

    y = 0;
    while (y < BUTTON_HEIGHT) //(y < BUTTON_HEIGHT)
    {
        x = 0;
        while (x < BUTTON_WIDTH) //(x < BUTTON_WIDTH)
        {
            fill_pix_ui(w, x + butt->x, y + butt->y, 0x778899);
            //printf("color at x: %d | y: %d = %d \n", x + butt->x, y + butt->y,w->data_ui[y + butt->y * WINDOW_WIDTH + x + butt->x]);
            x++;
        }
        y++;
    }
  //  mlx_string_put(w->mlx_ptr, w->win_ptr,  butt->x, butt->y + DISPLAY_HEIGHT, 255255255, butt->str);
    // mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
	// w->ui_img_ptr, 0, DISPLAY_HEIGHT);
}

void    draw_buttons(t_lst_display *win)
{
    int i;

    i = 0;
   while (i < BUTTON_NUMBER)
    {
        draw_button(win, &win->button_lst[i]);
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
   //butt->pt_function_init = function;

}

void    initialise_button_lst(t_lst_display *win)
{
    create_button(&(win->button_lst[0]), 5 , 110, "mandelbrot", &mandelbrot);
    create_button(&(win->button_lst[1]), 67, 110, "Julia", &mandelbrot);
}

