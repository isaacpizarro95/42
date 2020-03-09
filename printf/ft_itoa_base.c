/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:17:59 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/09 18:55:22 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p_itoa_base(unsigned long int number, char *base)
{
	unsigned long int	count;
	unsigned long int	tmp;
	char				*res;
	unsigned long int	base_length;

	base_length = (unsigned long int)ft_strlen(base);
	count = 1;
	tmp = number;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = number;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}

char	*ft_itoa_base(unsigned int number, char *base)
{
	unsigned int	count;
	unsigned int	tmp;
	char			*res;
	unsigned int	base_length;

	base_length = ft_strlen(base);
	count = 1;
	tmp = number;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = number;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
