/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:42:43 by pmontese          #+#    #+#             */
/*   Updated: 2020/02/20 18:37:37 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	if (count < 0 || size < 0)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(char) * count * size)))
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
