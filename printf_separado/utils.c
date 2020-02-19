/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:39 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/19 19:12:48 by ipizarro         ###   ########.fr       */
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

t_struct	*ft_zeros(t_struct *list, long int size)
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
	return (list);
}

t_struct	*ft_spaces(t_struct *list)
{
	long int i;

	i = (long int)ft_strlen(list->str);
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
	long int i;

	i = (long int)ft_strlen(list->str);
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

long int	get_number(t_struct *list)
{
	int 		i;
	int 		j;
	char		*nbr;
	long int	n;

	i = 0;
	j = 0;
	nbr = (char*)malloc(sizeof(char) * ft_strlen(list->set));
	while (ft_isdigit(list->set[i]))
	{
		nbr[j] = list->set[i];
		i++;
		j++;
	}
	n = (long int)ft_atoi(nbr);
	free(nbr);
	return (n);
}
