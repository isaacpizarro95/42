/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:42:02 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/25 02:23:22 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct			s_struct
{
	const char			*format;
	char				*set;
	char				*str;
	char				conversion;
	va_list				args;
	long int			neg;
	unsigned long int	precision;
	unsigned long int	width;
	unsigned long int	asterisk_width;
	unsigned long int	asterisk_precision;
	char				zero;
	int					len;
	int					i;
}						t_struct;

int			ft_printf(const char *format, ...);
int			parser(t_struct *list);
t_struct	*real_parser(t_struct *list);
t_struct	*update_set(t_struct *list);
t_struct	*ft_start(t_struct *list);
t_struct	*ft_asterisk(t_struct *list);
t_struct	*ft_put_precision_integers(t_struct *list);
t_struct	*ft_aux_put_precision_integers(t_struct *list);
t_struct	*ft_precision(t_struct *list);
t_struct	*ft_put_witdh(t_struct *list);
t_struct	*ft_width(t_struct *list);
t_struct	*ft_hyphen(t_struct *list);
t_struct	*ft_spaces(t_struct *list);
t_struct	*ft_zeros(t_struct *list, unsigned long int size);
t_struct	*ft_sign(t_struct *list);
t_struct	*ft_base_hexadecimal(unsigned long int k, t_struct *list);
char		*ft_aux_hexadecimal(unsigned long int k, char *str, t_struct *list);
t_struct	*ft_conversion(t_struct *list);
t_struct	*ft_c_conversion(t_struct *list);
t_struct	*ft_aux_c_conversion(t_struct *list, char c);
t_struct	*ft_s_conversion(t_struct *list);
t_struct	*ft_int_conversion(t_struct *list);
t_struct	*ft_p_conversion(t_struct *list);
t_struct	*list_reinitialize(t_struct *list);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalpha(int c);
int			ft_iscontained(char c, const char *set);
int			ft_isdigit(int c);
int			ft_isspace(int c);
char		*ft_itoa(int n);
char		*ft_unsigned_itoa(unsigned long int n);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_nbrlen(long int nbr);
void		ft_putchar(char c);
void		ft_putstr(char *s);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
