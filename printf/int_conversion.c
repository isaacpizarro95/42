/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:09:13 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 19:43:22 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_int_conversion(t_struct *list)
{
	int j;

	j = va_arg(list->args, long int);
	if (j < 0 && j != -2147483648)
	{
		list->neg = 1;
		j = j * -1;
	}
	list->str = ft_itoa(j);
}

void	ft_int_conversion(t_struct *list)
{
	unsigned long int	i;

	if (list->conversion == 'u')
		list->str = ft_unsigned_itoa(va_arg(list->args, unsigned long int));
	else if (list->conversion == 'x' || list->conversion == 'X')
	{
		i = va_arg(list->args, unsigned long int);
		ft_base_hexadecimal(i, list);
	}
	else
		ft_aux_int_conversion(list);
	if (*list->str == '0' && list->precision == 0
	&& ft_iscontained('.', list->set))
		list->str = "";
	if (list->precision > (long int)ft_strlen(list->str))
		ft_put_precision_integers(list);
	else if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		if (list->conversion == 'd' || list->conversion == 'i')
			ft_sign(list);
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
}
