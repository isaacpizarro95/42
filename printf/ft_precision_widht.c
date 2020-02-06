/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_widht.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:49:44 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 19:55:05 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_number(t_list *list, int i)
{
	int		j;
	char	*nbr;

	j = 0;
	nbr = NULL;
	while (ft_isdigit(list->set[i]))
	{
		nbr[j] = list->set[i];
		i++;
		j++;
	}
	return (nbr);
}

t_list	*ft_width(t_list *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (ft_iscontained('*', list->set))
		list->width = list->asterisk;
	else
	{
		while (list->set[i] != '.' || ft_isdigit(list->set[i]) == 0
		|| list->set[i] != '\0')
			i++;
		if (list->set[i] = '0')
		{
			list->zero = list->set[i];
			i++;
		}
		nbr = get_number(list, &i);
		if (nbr == NULL)
			return (list);
		else
			list->width = ft_atoi(nbr);
	}
	return (list);
}

t_list	*ft_precision(t_list *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		i++;
		nbr = get_number(list, &i);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
	}
	if (ft_iscontained('*', list->set))
		list->asterisk = va_arg(list->args, long int);
	return (list);
}
