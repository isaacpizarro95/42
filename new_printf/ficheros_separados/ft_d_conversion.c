/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:19:16 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:17:38 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_d_conversion(t_struct *list)
{
	long int	i;
	char		*str;
	char		*new_str;

	i = 0;
	str = ft_itoa(va_arg(list->args, int));
	if (list->precision > list->width && list->precision > (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_precision_integers(str, new_str, list);
		free(new_str);
		ft_putstr(str);
		list->len += list->precision;
	}
	else
	{
		if (list->width > (long int)ft_strlen(str))
		{
			if (list->precision > (long int)ft_strlen(str))
			{
				new_str = (char*)malloc(sizeof(char));
				str = ft_put_precision_integers(str, new_str, list);
				free(new_str);
				if (ft_iscontained('-', list->set))
				{
					new_str = (char*)malloc(sizeof(char));
					str = ft_hyphen(str, new_str, list);
					free(new_str);
				}
				else
				{
					while (i < list->width - list->precision)
					{
						ft_putchar(' ');
						i++;
					}
				}
				ft_putstr(str);
				list->len += list->width;
			}
			else
			{
				new_str = (char*)malloc(sizeof(char));
				str = ft_put_witdh(str, new_str, list);
				ft_putstr(str);
				free(new_str);
			}
		}
		else
		{
			ft_putstr(str);
			list->len += ft_strlen(str);
		}
	}
	return (list);
}
