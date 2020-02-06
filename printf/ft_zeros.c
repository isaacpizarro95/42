/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:48:16 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 19:55:08 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*aux_zeros(char *str, int size)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (size <= ft_strlen(str))
		return (str);
	else
	{
		while (i < size - ft_strlen(str))
		{
			new_str[i] = '0';
			i++;
		}
		while (str)
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		return (new_str);
	}
}

char	*ft_zeros(char *str, t_list *list)
{
	int		size;

	if (!(list->precision) && list->zero == '0')
	{
		if (list->asterisk > 0)
			size = list->asterisk;
		else
			size = list->width;
	}
	else
		size = list->precision;
	return (aux_zeros(str, size));
}
