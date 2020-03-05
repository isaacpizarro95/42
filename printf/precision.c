/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:02:29 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/05 19:38:42 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_aux_put_precision_integers(t_struct *list)
{
	long int j;

	j = 0;
	while (j < list->width - list->precision)
	{
		ft_putchar(' ');
		j++;
	}
	ft_aux_pointer(list);
	ft_zeros(list, list->precision);
}

void	ft_aux_put_precision_integers(t_struct *list)
{
	long int j;

	j = 0;
	if (list->conversion == 'p')
		list->width -= 2;
	if (list->neg == 1)
		list->width--;
	if (ft_iscontained('-', list->set) || list->hyphen == 1)
	{
		ft_aux_pointer(list);
		ft_zeros(list, list->precision);
		while (j < list->width - list->precision)
		{
			ft_putchar(' ');
			j++;
		}
	}
	else
		ft_aux_aux_put_precision_integers(list);
	list->len += list->width;
}

void	ft_put_precision_integers(t_struct *list)
{
	long int	i;
	long int	j;

	list->zero = '\0';
	i = (long int)ft_strlen(list->str);
	j = 0;
	if (list->width > list->precision)
		ft_aux_put_precision_integers(list);
	else
	{
		ft_sign(list);
		ft_aux_pointer(list);
		while (j < list->precision - i)
		{
			ft_putchar('0');
			j++;
		}
		ft_putstr(list->str);
		list->len += list->precision;
	}
}

void	ft_precision(t_struct *list)
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
}
