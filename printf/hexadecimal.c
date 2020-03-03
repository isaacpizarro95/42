/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:44:27 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 18:51:14 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_aux_hexadecimal(unsigned long int k, char *str, t_struct *list)
{
	unsigned long int	i;
	int					j;
	char				*hexadecimal;

	j = 0;
	if (list->conversion == 'x' || list->conversion == 'p')
		hexadecimal = "0123456789abcdef";
	else
		hexadecimal = "0123456789ABCDEF";
	while (k >= 16)
	{
		i = k % 16;
		str[j] = hexadecimal[i];
		k = k / 16;
		j++;
	}
	str[j] = hexadecimal[k];
	hexadecimal = NULL;
	return (str);
}

void	ft_base_hexadecimal(unsigned long int k, t_struct *list)
{
	size_t	j;
	char	*str;
	char	*aux;

	str = (char*)malloc(sizeof(char));
	aux = (char*)malloc(sizeof(char));
	j = 0;
	ft_aux_hexadecimal(k, str, list);
	while (j < ft_strlen(str))
	{
		aux[j] = str[ft_strlen(str) - 1 - j];
		j++;
	}
	list->str = aux;
	free(str);
	free(aux);
	str = NULL;
	aux = NULL;
}
