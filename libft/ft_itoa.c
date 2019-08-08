/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:37:15 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/04 18:40:14 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char		*nbr;
	int long	nb;
	int			i;
	int			size;

	nb = n;
	i = 0;
	size = ft_get_int_size(nb);
	if (!(nbr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		nbr[i++] = '-';
		size--;
	}
	while (size > 0)
	{
		nbr[i] = ((nb / ft_power(10, size - 1)) + '0');
		nb = nb % ft_power(10, size - 1);
		i++;
		size--;
	}
	nbr[i] = '\0';
	return (nbr);
}
