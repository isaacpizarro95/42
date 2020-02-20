/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:02:29 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/20 17:27:40 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_aux_put_precision_integers(long int i, t_struct *list)
{
	int j;

	j = 0;
	if (ft_iscontained('-', list->set))
	{
		ft_zeros(list, list->precision);
		while (i < list->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (j < list->width - list->precision)
		{
			ft_putchar(' ');
			j++;
		}
		ft_zeros(list, list->precision);
	}
	list->len += list->width;
	return (list);
}

t_struct	*ft_put_precision_integers(t_struct *list)
{
	long int	i;
	long int	j;

	list->zero = '\0';
	i = (long int)ft_strlen(list->str);
	j = 0;
	if (list->width > list->precision)
		ft_aux_put_precision_integers(i, list);
	else
	{
		ft_sign(list);
		while (j < list->precision - i)
		{
			ft_putchar('0');
			j++;
		}
		ft_putstr(list->str);
		list->len += list->precision;
	}
	return (list);
}

t_struct	*ft_precision(t_struct *list)
{
	int i;

	i = 0;
	if (list->asterisk_precision)
		list->precision = list->asterisk_precision;
	else
	{
		while (list->set[i] != '.')
			i++;
		i++;
		while (list->set[i] >= '0' && list->set[i] <= '9')
			list->precision = (list->precision * 10) + (list->set[i++] - '0');
	}
	return (list);
}
