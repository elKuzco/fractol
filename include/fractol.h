/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:10 by qlouisia          #+#    #+#             */
/*   Updated: 2019/08/08 18:56:16 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

typedef struct s_lst_fractol 
{
	void *img_ptr;
	int *data;
	int size_l;
	int bpp;
	int endian;
	void *mlx_ptr;
	void *win_ptr;
	int w_width;
	int w_height;
	
} t_lst_display;


#endif

