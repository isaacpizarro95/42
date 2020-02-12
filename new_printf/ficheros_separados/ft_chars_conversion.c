/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:20:56 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:17:27 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_s_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;
	char		*new_str;

	list->zero = '\0';
	str = va_arg(list->args, char*);
	new_str = (char*)malloc(sizeof(char));
	str = ft_put_precision_chars(str, new_str, list);
	new_str = NULL;
	free(new_str);
	if (list->width > (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, new_str, list);
		new_str = NULL;
		free(new_str);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		list->len += ft_strlen(str);
	}
	return (list);
}

t_struct	*ft_c_conversion(t_struct *list)
{
	char		*str;
	char		*new_str;

	str = (char*)malloc(sizeof(char));
	*str = va_arg(list->args, int);
	if (list->width > 1)
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, new_str, list);
		ft_putstr(str);
		new_str = NULL;
		free(new_str);
	}
	else
	{
		ft_putchar(*str);
		list->len++;
	}
	str = NULL;
	free(str);
	return (list);
}
