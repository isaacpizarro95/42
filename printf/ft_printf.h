/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:18:30 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 18:24:49 by ipizarro         ###   ########.fr       */
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
	char		conversion;
	va_list		args;
	long int	precision;
	long int	width;
	long int	asterisk;
	char		zero;
	int			len;
	int			i;
}				t_struct;

int			ft_printf(const char *format, ...);
int			parser(t_struct *list);
void		update_set(t_struct *list);
void		ft_start(t_struct *list);
t_struct	*ft_hyphen(char *chain, t_struct *list);
t_struct	*ft_precision(t_struct *list);
t_struct	*ft_width(t_struct *list);
char		*get_number(t_struct *list, int i, char *nbr);
char		*ft_put_precision(char *str, t_struct *list);
char		*ft_zeros(char *str, t_struct *list);
char		*aux_zeros(char *str, size_t size);
t_struct	*ft_conversion(t_struct *list);
t_struct	*ft_c_conversion(t_struct *list);
t_struct	*ft_s_conversion(t_struct *list);

#endif
