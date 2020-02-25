/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:39 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 00:41:21 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_sign(t_struct *list)
{
	if (list->neg == 1)
	{
		ft_putchar('-');
		list->len++;
	}
	return (list);
}

t_struct	*ft_zeros(t_struct *list, unsigned long int size)
{
	unsigned long int i;

	i = (unsigned long int)ft_strlen(list->str);
	ft_sign(list);
	while (i < size)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(list->str);
	return (list);
}

t_struct	*ft_spaces(t_struct *list)
{
	unsigned long int i;

	i = (unsigned long int)ft_strlen(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
	if (list->conversion == 'p')
	{
		ft_putstr("0x");
		list->len += 2;
	}
	ft_sign(list);
	ft_putstr(list->str);
	return (list);
}

t_struct	*ft_hyphen(t_struct *list)
{
	unsigned long int i;

	i = (unsigned long int)ft_strlen(list->str);
	if (list->conversion == 'p')
	{
		ft_putstr("0x");
		list->len += 2;
	}
	ft_sign(list);
	ft_putstr(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (list);
}
