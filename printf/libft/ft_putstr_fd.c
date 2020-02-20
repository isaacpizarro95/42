/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:10:17 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/19 20:50:06 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char c;

	if (s)
	{
		while (*s)
		{
			c = *s;
			ft_putchar_fd(c, fd);
			s++;
		}
	}
}
