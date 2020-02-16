/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:15:56 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 13:42:50 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_asterisk(t_struct *list)
{
	int i;

	i = 0;
	while (list->set[i] != '.' || list->set[i] != '\0')
	{
		if (list->set[i] == '*')
			list->asterisk_width = va_arg(list->args, long int);
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
				list->asterisk_precision = va_arg(list->args, long int);
			i++;
		}
	}
	return (list);
}