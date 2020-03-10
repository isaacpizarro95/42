/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:56:21 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/10 19:09:47 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_struct	*list;
	int			len_outpt;

	if (!(list = malloc(sizeof(t_struct))))
		return (-1);
	list->format = format;
	va_start(list->args, format);
	len_outpt = parser(list);
	list->format = NULL;
	list->i = 0;
	list->len = 0;
	va_end(list->args);
	free(list);
	return (len_outpt);
}
