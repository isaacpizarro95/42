/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:44:10 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/28 19:44:14 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_unsigned_itoa(unsigned long int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
