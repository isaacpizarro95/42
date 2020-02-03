/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:18:30 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/03 21:30:51 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <ctype.h>
#include "libft/libft.h"

typedef struct	s_list
{
	const char	*format;
	char		*set;
	char		conversion;
	va_list		args;
	long int	precision;
	long int	width;
	long int	asterisk;
	char		zero;
	int			len;
	int			i;
}				t_list;

int				ft_printf(const char *format, ...);

#endif
