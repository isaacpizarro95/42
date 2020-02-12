/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:13:45 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:03 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_put_witdh(char *str, char *new_str, t_struct *list)
{
	long int 	i;
	char		*new_chain;

	new_chain = (char*)malloc(sizeof(char));
	if (ft_iscontained('-', list->set))
		new_str = ft_hyphen(str, new_chain, list);
	else
	{
		if (list->zero != '\0' && list->width > (long int)ft_strlen(str))
			new_str = ft_zeros(str, new_chain, list);
		else
		{
			i = 0;
			while (i < list->width - (long int)ft_strlen(str))
			{
				new_str[i] = ' ';
				i++;
			}
			while (i < list->width)
			{
				new_str[i] = *str;
				str++;
				i++;
			}
		}
	}
	free(new_chain);
	list->len += list->width;
	return (new_str);
}

t_struct	*ft_width(t_struct *list)
{
	int		i;
	int		j;
	char	*nbr;

	i = 0;
	j = 0;
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
		if (list->set[i] == '0')
		{
			list->zero = list->set[i];
			i++;
		}
		nbr = (char*)malloc(sizeof(char));
		get_number(list, i, nbr);
		if (nbr)
			list->width = (long int)ft_atoi(nbr);
		nbr = NULL;
		free(nbr);
	}
	return (list);
}
