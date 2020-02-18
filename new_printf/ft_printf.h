/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:39:05 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/18 17:57:50 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <ctype.h>
#include "libft/libft.h"

typedef struct	s_struct
{
	const char	*format;
	char		*set;
	char		*str;
	char		conversion;
	va_list		args;
	long int	neg;
	long int	precision;
	long int	width;
	long int	asterisk_width;
	long int	asterisk_precision;
	char		zero;
	int			sign;
	int			len;
	int			i;
}				t_struct;

int			ft_printf(const char *format, ...);
int			parser(t_struct *list);
t_struct	*real_parser(t_struct *list);
t_struct	*update_set(t_struct *list);
t_struct	*ft_start(t_struct *list);
t_struct	*ft_precision(t_struct *list);
t_struct	*ft_aux_precision(t_struct *list);
t_struct	*ft_asterisk(t_struct *list);
t_struct	*ft_width(t_struct *list);
t_struct	*ft_aux_widht(int i, int j, t_struct *list);
char		*ft_put_precision_chars(char *new_str, t_struct *list);
t_struct	*ft_put_precision_integers(t_struct *list);
t_struct	*ft_aux_put_precision_integers(long int i, t_struct *list);
t_struct	*ft_put_witdh(t_struct *list);
t_struct	*ft_hyphen(t_struct *list);
t_struct	*ft_spaces(t_struct *list);
t_struct	*ft_zeros(t_struct *list);
t_struct	*ft_sign(t_struct *list);
t_struct	*ft_base_hexadecimal(unsigned long int k, t_struct *list);
char		*ft_aux_hexadecimal(unsigned long int k, char *str, t_struct *list);
t_struct	*ft_conversion(t_struct *list);
t_struct	*ft_c_conversion(t_struct *list);
t_struct	*ft_s_conversion(t_struct *list);
t_struct	*ft_int_conversion(t_struct *list);
t_struct	*ft_p_conversion(t_struct *list);
t_struct	*list_initialize(t_struct *list);

#endif
