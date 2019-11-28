/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:22 by qlouisia          #+#    #+#             */
/*   Updated: 2019/11/28 14:13:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*thread_manage(t_lst_display *win)
{
	pthread_t	me;
	int			i;
	int			start;

	i = 0;
	me = pthread_self();
	while (me != win->id_tread[i])
		i++;
	start = i * win->display_w / THREAD_NUMBER;
	win->pt_function(win, start);
	pthread_exit(NULL);
}

int		initialise_thread(t_lst_display *w)
{
	int i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		if (pthread_create(&w->id_tread[i], NULL, (void *)thread_manage, w))
			return (quit_program(w));
		i++;
	}
	i = 0;
	while (i < THREAD_NUMBER)
	{
		pthread_join(w->id_tread[i], NULL);
		i++;
	}
	return (1);
}
