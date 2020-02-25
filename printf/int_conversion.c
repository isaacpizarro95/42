/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:09:13 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 21:42:37 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_aux_int_conversion(t_struct *list)
{
	int j;

	j = va_arg(list->args, long int);
	if (j < 0 && j != -2147483648)
	{
		list->neg = 1;
		j = j * -1;
	}
	list->str = ft_itoa(j);
	return (list);
}

t_struct	*ft_int_conversion(t_struct *list)
{
	unsigned long int	i;

	if (list->conversion == 'u')
		list->str = ft_unsigned_itoa(va_arg(list->args, unsigned long int));
	else if (list->conversion == 'x' || list->conversion == 'X')
	{
		i = va_arg(list->args, unsigned long int);
		if (i == 0)
			list->str = "0";
		else
			ft_base_hexadecimal(i, list);
	}
	else
		ft_aux_int_conversion(list);
	if (list->precision > (unsigned long int)ft_strlen(list->str))
		ft_put_precision_integers(list);
	else if (list->width > (unsigned long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		if (list->conversion == 'd' || list->conversion == 'i')
			ft_sign(list);
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
	return (list);
}
