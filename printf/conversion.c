/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:57 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 18:45:09 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(t_struct *list)
{
	if (list->conversion == 'c' || list->conversion == '%')
		ft_c_conversion(list);
	else if (list->conversion == 's')
		ft_s_conversion(list);
	else if (list->conversion == 'd' || list->conversion == 'i' ||
	list->conversion == 'u' || list->conversion == 'x' ||
	list->conversion == 'X')
		ft_int_conversion(list);
	else if (list->conversion == 'p')
		ft_p_conversion(list);
}
