/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:02 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/09 10:57:54 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_s_conversion(t_struct *list)
{
	if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
}

void	ft_s_conversion(t_struct *list)
{
	int		boolean;
	char	*str;

	boolean = 0;
	list->str = va_arg(list->args, char*);
	if (list->str == NULL)
		list->str = "(null)";
	if (ft_iscontained('.', list->set) &&
	list->precision < (long int)ft_strlen(list->str)
	&& list->asterisk_precision >= 0)
	{
		str = ft_strdup(list->str);
		list->str = NULL;
		free(list->str);
		boolean = 1;
		if (list->precision == 0)
			list->str = ft_strdup("");
		else
			list->str = ft_substr(str, 0, list->precision);
		free(str);
	}
	ft_aux_s_conversion(list);
	if (boolean == 1)
		free(list->str);
}

void	ft_aux_percent_conversion(t_struct *list, char c)
{
	long int i;

	i = 1;
	while (i < list->width)
	{
		ft_putchar('0');
		i++;
	}
	ft_putchar(c);
}

void	ft_aux_c_conversion(t_struct *list, char c)
{
	long int i;

	i = 1;
	if (ft_iscontained('-', list->set) || list->hyphen == 1)
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
}

void	ft_c_conversion(t_struct *list)
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
}
