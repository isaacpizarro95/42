/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:09:35 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/19 18:36:00 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_p_conversion(t_struct *list)
{
	unsigned long int i;

	list->zero = '\0';
	i = va_arg(list->args, unsigned long int);
	ft_base_hexadecimal(i, list);
	if (list->width > (long int)ft_strlen(list->str) + 2)
		ft_put_witdh(list);
	else
	{
		ft_putstr("0x");
		ft_putstr(list->str);
		list->len += (long int)ft_strlen(list->str) + 2;
	}
	return (list);
}
