/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:45:37 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 19:44:02 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_p_conversion(t_struct *list)
{
	if (list->precision > (long int)ft_strlen(list->str) + 2)
	{
		ft_put_precision_integers(list);
		list->len += 2;
	}
	else if (list->width > (long int)ft_strlen(list->str) + 2)
		ft_put_witdh(list);
	else
	{
		ft_putstr("0x");
		ft_putstr(list->str);
		list->len += (long int)ft_strlen(list->str) + 2;
	}
}

void	ft_p_conversion(t_struct *list)
{
	unsigned long int i;

	list->zero = '\0';
	i = va_arg(list->args, unsigned long int);
	if (i == 0 && list->precision == 0 && ft_iscontained('.', list->set))
	{
		list->str = "";
		if (list->width > (long int)ft_strlen(list->str))
			ft_put_witdh(list);
		else
		{
			ft_aux_pointer(list);
			list->len += 2;
		}
		return ;
	}
	else
		ft_base_hexadecimal(i, list);
	ft_aux_p_conversion(list);
}
