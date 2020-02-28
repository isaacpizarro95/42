/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:46:03 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/28 19:46:05 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_put_witdh(t_struct *list)
{
	if (list->neg == 1)
		list->width--;
	if (ft_iscontained('-', list->set))
		ft_hyphen(list);
	else if (list->zero == '0' && !(ft_iscontained('.', list->set)))
		ft_zeros(list, list->width);
	else
		ft_spaces(list);
	list->len += list->width;
	return (list);
}

t_struct	*ft_width(t_struct *list)
{
	int i;

	i = 0;
	if (list->set[i] == '0')
	{
		list->zero = list->set[i];
		i++;
	}
	if (ft_iscontained('*', list->set))
		list->width = list->asterisk_width;
	else
	{
		while (list->set[i] != '\0')
		{
			if (list->set[i] == '.' || ft_isdigit(list->set[i]) == 1)
				break ;
			i++;
		}
		while (list->set[i] >= '0' && list->set[i] <= '9')
			list->width = (list->width * 10) + (list->set[i++] - '0');
	}
	return (list);
}
