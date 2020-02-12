/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:12:40 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/12 14:18:16 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_put_precision_integers(char *str, char *new_str, t_struct *list)
{
	long int	i;
	long int	j;

	i = 0;
	j = 0;
	if (ft_iscontained('.', list->set) && list->precision > (long int)ft_strlen(str))
	{
		while (i < list->precision - (long int)ft_strlen(str))
		{
			new_str[i] = '0';
			i++;
		}
		while (i < list->precision)
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		return (new_str);
	}
	return (str);
}

char		*ft_put_precision_chars(char *str, char *new_str, t_struct *list)
{
	long int	i;

	i = 0;
	if (ft_iscontained('.', list->set) && list->precision < (long int)ft_strlen(str))
	{
		if (list->precision == 0)
			new_str[i] = '\0';
		while (i < list->precision)
		{
			new_str[i] = str[i];
			i++;
		}
		return (new_str);
	}
	return (str);
}

t_struct	*ft_precision(t_struct *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		i++;
		nbr = (char*)malloc(sizeof(char));
		get_number(list, i, nbr);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
		nbr = NULL;
		free(nbr);
	}
	return (list);
}
