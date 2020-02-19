/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:42:43 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/21 17:20:21 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
