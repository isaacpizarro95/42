/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:58:47 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/03 19:57:43 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_asterisk_precision(t_struct *list)
{
	int i;

	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		while (list->set[i] != '\0')
		{
			if (list->set[i] == '*')
				list->asterisk_precision = va_arg(list->args, int);
			i++;
		}
		if (list->asterisk_precision < 0)
			list->hyphen = 1;
	}
}

void	ft_asterisk_widht(t_struct *list)
{
	int i;

	i = 0;
	while (list->set[i] != '.' && list->set[i] != '\0')
	{
		if (list->set[i] == '*')
			list->asterisk_width = va_arg(list->args, int);
		i++;
	}
	if (list->asterisk_width < 0)
	{
		list->asterisk_width *= -1;
		list->hyphen = 1;
	}
}

void	ft_asterisk(t_struct *list)
{
	ft_asterisk_widht(list);
	ft_asterisk_precision(list);
}
