/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:46:10 by qlouisia          #+#    #+#             */
/*   Updated: 2019/12/01 18:55:16 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <pthread.h>
#include "../libft/libft.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1200
#define THREAD_NUMBER 4 
#define DISPLAY_WIDTH 800 
#define DISPLAY_HEIGHT 800
#define INTMAX 2147483647

typedef struct s_lst_complex
{
	double	c_re;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
} t_complex;

typedef struct s_lst_comp_trig
{
	double	c_re;
	double	c_re2;
	double	c_im2;
	double	c_2;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	double	inv_re;
	double	inv_im;
	double	n_zre;
	double	n_zim;
	double	z_2;

} t_complex_trig;


typedef struct s_lst_fractol 
{
	void *display_img_ptr;
	int *data_display;
	int *data_ui;
	void *ui_img_ptr;
	int size_l;
	int bpp;
	int endian;
	void *mlx_ptr;
	void *win_ptr;
	int display_w;
	int display_h;
	pthread_t id_tread[THREAD_NUMBER];
	void (*pt_function)(struct s_lst_fractol *, int);
	void (*pt_function_init)(struct s_lst_fractol *);
	double Minreal;
	double Minima;
	double Maxreal;
	double Maxima; 
	double Real_scale;
	double Ima_scale;
	t_bool julia_mod_enable;
	double julia_re;
	double julia_im;
	int Max_it;
	double zoom_scale;
	int clr_m;
	unsigned int palette[16];
	int palettte_size;
} t_lst_display;

void color_wheel(t_lst_display *win);
int initialise_graphic(t_lst_display *win, void *mlx_serv, char *tittle);
void initialise_fractal_mandel(t_lst_display *win);
void	fill_pix(t_lst_display *img, int x, int y, int color);
void mandelbrot(t_lst_display *win, int start );
void initialise_fractal_julia(t_lst_display *win);
void julia(t_lst_display *win, int start );
void initialise_fractal_hazard(t_lst_display *win);
void hazard(t_lst_display *win, int start );
void initialise_fractal_tricorn(t_lst_display *win);
void tricorn(t_lst_display *win, int start );
void burningship(t_lst_display *win, int start );
void initialise_fractal_burningship(t_lst_display *win);
void initialise_fractal_mandel3(t_lst_display *win);
void mandel3(t_lst_display *win, int start );
void julia3(t_lst_display *win, int start );
void initialise_fractal_julia3(t_lst_display *win);
void initialise_fractal_phoenix(t_lst_display *win);
void phoenix(t_lst_display *win, int start );
void change_fractal(int keycode, t_lst_display *p);
void	refresh_image(t_lst_display *win);
int quit_program(t_lst_display *env);
int mouse_control(int m_code, int x, int y, t_lst_display *win);
int	move(int keycode, t_lst_display *param);
unsigned int colormod (int n, t_lst_display *win);
void set_color_to_mode1(t_lst_display *win);
unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b);
void set_color_to_rainbow(t_lst_display *win);
void	heart(t_lst_display *win, int start);
void	initialise_fractal_heart(t_lst_display *win);
int initialise_thread(t_lst_display *win);
int motion_hook(int x, int y, t_lst_display *win);
void	print_ui(t_lst_display *env);
int		expose_hook(t_lst_display *win);
void display(void *ser, t_lst_display *win);
int		get_input(int keycode, t_lst_display *win);
void	feigen(t_lst_display *win, int start);
void	initialise_fractal_feigen(t_lst_display *win);
void pines(t_lst_display *win, int start );
void initialise_fractal_pines(t_lst_display *win);
void	set_struct_comp(t_complex_trig *c, double c_im);
void draw_background(t_lst_display *win, int y, int x, unsigned int color);
#endif