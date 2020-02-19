/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:02 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/19 19:15:13 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_s_conversion(t_struct *list)
{
	char	*new_str;

	list->zero = '\0';
	list->str = va_arg(list->args, char*);
	if (ft_iscontained('.', list->set) &&
	list->precision < (long int)ft_strlen(list->str))
	{
		if (list->precision == 0)
			list->str = "";
		else
			list->str = ft_put_precision_chars(list);
	}
	if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
	return (list);
}

t_struct	*ft_aux_c_conversion(t_struct *list, char c)
{
	int i;

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
