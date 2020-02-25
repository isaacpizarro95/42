/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:09:35 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 21:40:31 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_p_conversion(t_struct *list)
{
	unsigned long int i;

	list->zero = '\0';
	i = va_arg(list->args, unsigned long int);
	if (i == 0 && list->precision == 0 && ft_iscontained('.', list->set))
	{
		list->str = "";
		if (list->width > ft_strlen(list->str))
			ft_put_witdh(list);
		else	
		{
			ft_aux_pointer(list);
			list->len += 2;
		}
		return (list);
	}
	else
		ft_base_hexadecimal(i, list);
	if (list->precision > (unsigned long int)ft_strlen(list->str) + 2)
	{
		ft_put_precision_integers(list);
		list->len += 2;
	}
	else if (list->width > (unsigned long int)ft_strlen(list->str) + 2)
		ft_put_witdh(list);
	else
	{
		ft_putstr("0x");
		ft_putstr(list->str);
		list->len += (unsigned long int)ft_strlen(list->str) + 2;
	}
	return (list);
}
