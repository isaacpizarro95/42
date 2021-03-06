/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:05:46 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/20 18:37:50 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen(long int nbr)
{
	int				len;
	unsigned int	unbr;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		unbr = -nbr;
		len++;
	}
	else
		unbr = nbr;
	while (unbr != 0)
	{
		unbr = unbr / 10;
		len++;
	}
	return (len);
}
