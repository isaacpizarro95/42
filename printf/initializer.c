/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:57:50 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/04 17:32:38 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start(t_struct *list)
{
	if (ft_iscontained('*', list->set))
		ft_asterisk(list);
	if (ft_iscontained('.', list->set))
		ft_precision(list);
	ft_width(list);
	ft_conversion(list);
}

void	update_set(t_struct *list)
{
	int j;

	j = 0;
	while (ft_isalpha(list->format[list->i + j]) == 0
	&& list->format[list->i + j] != '%'
	&& list->format[list->i + j] != ' ' && list->format[list->i + j] != '\0')
		j++;
	list->set = ft_substr(list->format, list->i, j);
	list->i = list->i + j;
	if (list->format[list->i] != '\0' && list->format[list->i] != ' ')
	{
		list->conversion = list->format[list->i];
		list->i++;
	}
}

void	list_reinitialize(t_struct *list)
{
	list->i++;
	list->str = NULL;
	list->conversion = '\0';
	list->neg = 0;
	list->precision = 0;
	list->width = 0;
	list->asterisk_precision = 0;
	list->asterisk_width = 0;
	list->hyphen = 0;
	list->zero = '\0';
	update_set(list);
	ft_start(list);
	free(list->set);
}

void	real_parser(t_struct *list)
{
	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] == '%')
		{
			if (list->format[list->i + 1] == '%')
			{
				ft_putchar(list->format[list->i]);
				list->i = list->i + 2;
				list->len++;
			}
			else
				list_reinitialize(list);
		}
		else
		{
			ft_putchar(list->format[list->i]);
			list->i++;
			list->len++;
		}
	}
}

int		parser(t_struct *list)
{
	if (!(ft_iscontained('%', list->format)))
	{
		ft_putstr((char *)list->format);
		return (ft_strlen(list->format));
	}
	else
		real_parser(list);
	return (list->len);
}
