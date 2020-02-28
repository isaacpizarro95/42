/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:56:21 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/28 19:41:12 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_struct	*list;
	int			len_outpt;

	if (!(list = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	list->format = format;
	va_start(list->args, format);
	len_outpt = parser(list);
	va_end(list->args);
	list->format = NULL;
	free(list);
	//printf("La longitud es: %d\n", len_outpt);
	return (len_outpt);
}

int			main(void)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = &i;
	while (i < 5)
	{
		ft_printf("El número es: %i\n", i);
		i++;
	}
	return (0);
}
