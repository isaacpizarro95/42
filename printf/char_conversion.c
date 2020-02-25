/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:02 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 02:37:04 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_s_conversion(t_struct *list)
{
	list->zero = '\0';
	list->str = va_arg(list->args, char*);
	if (list->str)
	{
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
	}
	else
	{
		ft_putstr("(null)");
		list->len += 6;
	}
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

	list->zero = '\0';
	c = va_arg(list->args, int);
	if (list->width > 1)
		ft_aux_c_conversion(list, c);
	else
	{
		ft_putchar(c);
		list->len++;
	}
	return (list);
}
