/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:08:57 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/20 03:23:32 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_conversion(t_struct *list)
{
	if (list->conversion == 'c')
		ft_c_conversion(list);
	else if (list->conversion == 's')
		ft_s_conversion(list);
	else if (list->conversion == 'd' || list->conversion == 'i' ||
	list->conversion == 'u' || list->conversion == 'x' ||
	list->conversion == 'X')
		ft_int_conversion(list);
	else if (list->conversion == 'p')
		ft_p_conversion(list);
	return (list);
}
