/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:51:27 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/04 12:46:58 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "../include/colors.h"
#include <stdlib.h>

void	fill_pix(t_lst_display *img, int x, int y, int color)
{
	if ((x < img->display_w) && (x >= 0)
		&& (y < img->display_h) && (y >= 0))
	{
		img->data_display[y * img->display_w + x] = color;
	}
}

void	refresh_image(t_lst_display *win)
{
	int i;
	int n;

	n = win->display_w * win->display_h;
	i = 0;
	while (i < n)
	{
		win->data_display[i] = 0;
		i++;
	}
	initialise_thread(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
	win->display_img_ptr, 0, 0);
	draw_background((win), win->display_h, 0, GREY_UI);
	draw_buttons(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
	win->ui_img_ptr, 0, DISPLAY_HEIGHT);
	print_ui(win);
}

int		expose_hook(t_lst_display *win)
{
	refresh_image(win);
	return (1);
}

void	display(void *ser, t_lst_display *win)
{
	initialise_thread(win);
	mlx_hook(win->win_ptr, 17, 1L << 17, quit_program, win);
	mlx_hook(win->win_ptr, 2, 3, get_input, win);
	mlx_hook(win->win_ptr, 6, 0, motion_hook, win);
	mlx_mouse_hook(win->win_ptr, mouse_control, win);
	mlx_loop(ser);
}

void	draw_name_button(t_lst_display *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 15,
	138 + DISPLAY_HEIGHT, G_UI, "Mandel");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 90,
	138 + DISPLAY_HEIGHT, G_UI, "Julia");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 170,
	138 + DISPLAY_HEIGHT, G_UI, "Tri");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 235,
	138 + DISPLAY_HEIGHT, G_UI, "Ship");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 297,
	138 + DISPLAY_HEIGHT, G_UI, "Mande3");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 370,
	138 + DISPLAY_HEIGHT, G_UI, "Julia3");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 438,
	138 + DISPLAY_HEIGHT, G_UI, "Phoeni");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 510,
	138 + DISPLAY_HEIGHT, G_UI, "Feigen");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 580,
	138 + DISPLAY_HEIGHT, G_UI, "Heart");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 648,
	138 + DISPLAY_HEIGHT, G_UI, "Hazard");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 720,
	138 + DISPLAY_HEIGHT, G_UI, "Pines");
}
