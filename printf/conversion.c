/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:57 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/05 18:59:35 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(t_struct *list)
{
	if (list->conversion == 'c' || list->conversion == '%')
		ft_c_conversion(list);
	if (list->conversion == 's')
		ft_s_conversion(list);
	if (list->conversion == 'd' || list->conversion == 'i' ||
	list->conversion == 'u' || list->conversion == 'x' ||
	list->conversion == 'X' || list->conversion == 'p')
		ft_int_conversion(list);
}
