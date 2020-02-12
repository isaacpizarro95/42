/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:48:16 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:26 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_zeros(char *str, char *new_str, t_struct *list)
{
	long int i;

	i = 0;
	if (ft_iscontained('.', list->set))
		return (str);
	else
	{
		while (i < list->width)
		{
			if (i < (list->width - (long int)ft_strlen(str)))
				new_str[i] = '0';
			else
			{
				new_str[i] = *str;
				str++;
			}
			i++;
		}
		return (new_str);
	}
}
