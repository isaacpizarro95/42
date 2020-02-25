/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:58:47 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 00:46:56 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_asterisk(t_struct *list)
{
	int i;

	i = 0;
	while (list->set[i] != '.' && list->set[i] != '\0')
	{
		if (list->set[i] == '*')
			list->asterisk_width = va_arg(list->args, unsigned long int);
		if (list->asterisk_width < 0)
			list->asterisk_width = 0;
		i++;
	}
	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		while (list->set[i] != '\0')
		{
			if (list->set[i] == '*')
				list->asterisk_precision = va_arg(list->args, unsigned long int);
			if (list->asterisk_precision < 0)
				list->asterisk_precision = 0;
			i++;
		}
	}
	return (list);
}
