/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:02:29 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/19 19:14:05 by ipizarro         ###   ########.fr       */
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

char		*ft_put_precision_chars(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;
	char		*new_str;

	i = (long int)ft_strlen(list->str);
	j = 0;
	str = (char*)malloc(sizeof(char) * i);
	if (list->precision < i)
	{
		while (j < list->precision)
		{
			str[j] = list->str[j];
			j++;
		}
	}
	new_str = str;
	free(str);
	return (new_str);
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
		list->precision = get_number(list);
	}
	return (list);
}
