/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:29:04 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/21 19:07:26 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	i = 0;
	while ((i < n) && us1[i] == us2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (us1[i] - us2[i]);
}
