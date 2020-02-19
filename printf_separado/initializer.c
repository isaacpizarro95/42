/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:57:50 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/19 19:29:32 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_start(t_struct *list)
{
	if (ft_iscontained('*', list->set))
		ft_asterisk(list);
	if (ft_iscontained('.', list->set))
		ft_precision(list);
	ft_width(list);
	ft_conversion(list);
	return (list);
}

t_struct	*update_set(t_struct *list)
{
	int j;

	j = 0;
	while (ft_isalpha(list->format[list->i]) == 0)
	{
		list->set[j] = list->format[list->i];
		list->i++;
		j++;
	}
	list->conversion = list->format[list->i];
	list->i++;
	return (list);
}

t_struct	*list_reinitialize(t_struct *list)
{
	list->str = NULL;
	list->conversion = '\0';
	list->neg = 0;
	list->precision = 0;
	list->width = 0;
	list->asterisk_precision = 0;
	list->asterisk_width = 0;
	list->zero = '\0';
	return (list);
}

t_struct	*real_parser(t_struct *list)
{
	while (list->format[list->i] != '\0')
	{
		list_reinitialize(list);
		if (list->format[list->i] == '%')
		{
			if (list->format[list->i + 1] == '%')
			{
				ft_putchar(list->format[list->i]);
				list->i = list->i + 2;
				list->len++;
			}
			else
			{
				list->i++;
				list->set = (char*)malloc(sizeof(char));
				update_set(list);
				ft_start(list);
				free(list->set);
			}
		}
		ft_putchar(list->format[list->i]);
		list->i++;
		list->len++;
	}
	return (list);
}

int			parser(t_struct *list)
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
