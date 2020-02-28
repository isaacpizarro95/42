/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:02 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/28 19:35:34 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_s_conversion(t_struct *list)
{
	list->str = va_arg(list->args, char*);
	if (list->str == NULL)
		list->str = "(null)";
	if (ft_iscontained('.', list->set) &&
	list->precision < (unsigned long int)ft_strlen(list->str))
	{
		if (list->precision == 0)
			list->str = "";
		else
			list->str = ft_substr(list->str, 0, list->precision);
	}
	if (list->width > (unsigned long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
	return (list);
}

t_struct	*ft_aux_percent_conversion(t_struct *list, char c)
{
	unsigned long int i;

	i = 1;
	while (i < list->width)
	{
		ft_putchar('0');
		i++;
	}
	ft_putchar(c);
	return (list);
}

t_struct	*ft_aux_c_conversion(t_struct *list, char c)
{
	unsigned long int i;

	i = 1;
	if (ft_iscontained('-', list->set))
	{
		ft_putchar(c);
		while (i < list->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else if (list->zero == '0' && list->conversion == '%')
		ft_aux_percent_conversion(list, c);
	else
	{
		while (i < list->width)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(c);
	}
	list->len += list->width;
	return (list);
}

t_struct	*ft_c_conversion(t_struct *list)
{
	char c;

	if (list->conversion == 'c')
	{
		list->zero = '\0';
		c = va_arg(list->args, int);
	}
	else
		c = list->conversion;
	if (list->width > 1)
		ft_aux_c_conversion(list, c);
	else
	{
		ft_putchar(c);
		list->len++;
	}
	return (list);
}
