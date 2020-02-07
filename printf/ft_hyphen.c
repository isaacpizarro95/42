/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hyphen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:50:43 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 19:55:03 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hyphen(char *chain, t_list *list)
{
	int		i;
	char	*new_chain;

	i = 0;
	if (list->width <= ft_strlen(chain))
		return (chain);
	else
	{
		while (chain[i] != '\0')
		{
			new_chain[i] = chain[i];
			i++;
		}
		while (i < list->width)
		{
			new_chain[i] = ' ';
			i++;
		}
		return (new_chain);
	}
}