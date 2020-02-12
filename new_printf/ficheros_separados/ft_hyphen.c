/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hyphen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:50:43 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:35 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hyphen(char *chain, char *new_chain, t_struct *list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(chain))
	{
		new_chain[i] = chain[i];
		i++;
	}
	while (i < (size_t)list->width)
	{
		new_chain[i] = ' ';
		i++;
	}
	return (new_chain);
}
