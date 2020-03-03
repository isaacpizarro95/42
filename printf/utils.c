/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:39 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 19:46:17 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux_pointer(t_struct *list)
{
	if (list->conversion == 'p')
		ft_putstr("0x");
}

void	ft_sign(t_struct *list)
{
	if (list->neg == 1)
	{
		ft_putchar('-');
		list->len++;
	}
}

void	ft_zeros(t_struct *list, long int size)
{
	long int i;

	i = (long int)ft_strlen(list->str);
	ft_sign(list);
	while (i < size)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(list->str);
}

void	ft_spaces(t_struct *list)
{
	long int i;

	if (list->conversion == 'p')
		i = (long int)ft_strlen(list->str) + 2;
	else
		i = (long int)ft_strlen(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
	ft_aux_pointer(list);
	ft_sign(list);
	ft_putstr(list->str);
}

void	ft_hyphen(t_struct *list)
{
	long int i;

	if (list->conversion == 'p')
		i = (long int)ft_strlen(list->str) + 2;
	else
		i = (long int)ft_strlen(list->str);
	ft_aux_pointer(list);
	ft_sign(list);
	ft_putstr(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
}
