/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:53:44 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 19:55:01 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_c_conversion(t_list *list)
{
	int		i;
	char	c;
	char	*str;

	c = va_arg(list->args, char);
	*str = c;
	if (list->width > 0)
	{
		if (ft_iscontained('-', list->set))
			ft_putstr(ft_hyphen(str, list));
		else
		{
			i = 0;
			while (i < list->width - 1)
			{
				str[i] = ' ';
				i++;
			}
			str[i] = c;
			ft_putstr(str);
		}
		list->len += list->width;
	}
	else
	{
		ft_putchar(c);
		list->len++;
	}
	return (list);
}

t_list	*ft_conversion(t_list *list)
{
	if (list->conversion == 'c')
		ft_c_conversion(list);
	else if (list->conversion == 's')
		ft_s_conversion(list);
	else if (list->conversion == 'p')
		ft_p_conversion(list);
	else if (list->conversion == 'd' || list->conversion == 'i')
		ft_d_conversion(list);
	else if (list->conversion == 'u')
		ft_u_conversion(list);
	else if (list->conversion == 'x')
		ft_x_conversion(list);
	else if (list->conversion == 'X')
		ft_majx_conversion(list);
}
