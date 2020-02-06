/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:26:07 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/03 23:26:20 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start(t_list *list)
{
	list->i++;
	ft_precision(list);
	ft_width(list);
	ft_conversion(list);
}

void	update_set(t_list *list)
{
	int i;
	int j;

	i = list->i + 1;
	j = 0;
	while (!(ft_isalpha(list->format[i])))
	{
		list->set[j] = list->format[i];
		i++;
		j++;
	}
	list->conversion = list->format[i];
}

int		parser(t_list *list)
{
	if (!(ft_iscontained('%', list->format)))
	{
		ft_putstr(list->format);
		return (ft_strlen(list->format));
	}
	else
	{
		while (list->format[list->i] != '\0')
		{
			if (list->format[list->i] == '%')
			{
				update_set(list);
				ft_start(list);
			}
			ft_putchar(list->format[list->i]);
			list->i++;
			list->len++;
		}
	}
	return (list->len);
}

int		ft_printf(const char *format, ...)
{
	t_list	*list;
	int		len_outpt;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (-1);
	list->format = format;
	list->i = 0;
	list->len = 0;
	if (format)
	{
		va_start(list->args, format);
		len_outpt = parser(list);
		va_end(list->args);
	}
	free(list);
	return (len_outpt);
}

int		main(void)
{
	ft_printf("hola %c hombre", 'b');
	return (0);
}
