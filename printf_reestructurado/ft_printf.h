/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:39:05 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/16 14:35:48 by isaacpizarr      ###   ########.fr       */
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
	long int	precision;
	long int	width;
	long int	asterisk_width;
	long int	asterisk_precision;
	char		zero;
	int			len;
	int			i;
}				t_struct;

int			ft_printf(const char *format, ...);
int			parser(t_struct *list);
t_struct	*real_parser(t_struct *list);
t_struct	*update_set(t_struct *list);
void		ft_start(t_struct *list);
t_struct	*ft_precision(t_struct *list);
t_struct	*ft_asterisk(t_struct *list);
t_struct	*ft_width(t_struct *list);
char		*ft_put_precision_chars(char *new_str, t_struct *list);
t_struct	*ft_put_precision_integers(t_struct *list);
t_struct	*ft_aux_precision_integers(long int i, t_struct *list);
t_struct	*ft_put_witdh(t_struct *list);
t_struct	*ft_hyphen(t_struct *list);
t_struct	*ft_spaces(t_struct *list);
t_struct	*ft_zeros(t_struct *list);
t_struct	*ft_conversion(t_struct *list);
t_struct	*ft_c_conversion(t_struct *list);
t_struct	*ft_s_conversion(t_struct *list);
t_struct	*ft_d_conversion(t_struct *list);

#endif
