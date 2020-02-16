/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:53:18 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/16 04:57:34 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_sign(char *str, char *new_str, t_struct *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_iscontained('-', str))
	{
		new_str[i] = '-';
		i++;
		while (str[j] != '-')
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		j++;
		while (str[j])
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		return (new_str);
	}
	return (str);
}

char		*ft_hyphen(char *str, char *new_str, t_struct *list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < (size_t)list->width)
	{
		new_str[i] = ' ';
		i++;
	}
	return (new_str);
}

char		*ft_zeros(char *str, char *new_str, t_struct *list)
{
	long int	i;

	i = 0;
	if (ft_iscontained('.', list->set))
		return (str);
	else
	{
		while (i < list->width)
		{
			if (i < (list->width - (long int)ft_strlen(str)))
				new_str[i] = '0';
			else
			{
				new_str[i] = *str;
				str++;
			}
			i++;
		}
		return (new_str);
	}
	return (str);
}

char		*ft_put_precision_integers(char *str, t_struct *list)
{
	long int	i;
	long int	j;

	i = 0;
	j = 0;
	if (ft_iscontained('.', list->set) && list->precision > (long int)ft_strlen(str))
	{
		while (i < list->precision - (long int)ft_strlen(str))
		{
			list->aux[i] = '0';
			i++;
		}
		while (i < list->precision)
		{
			list->aux[i] = str[j];
			i++;
			j++;
		}
		return (list->aux);
	}
	return (str);
}

char		*ft_put_precision_chars(char *str, t_struct *list)
{
	long int	i;

	i = 0;
	if (ft_iscontained('.', list->set) && list->precision < (long int)ft_strlen(str))
	{
		if (list->precision == 0)
			list->aux[i] = '\0';
		while (i < list->precision)
		{
			list->aux[i] = str[i];
			i++;
		}
		return (list->aux);
	}
	return (str);
}

char		*ft_put_witdh(char *str, t_struct *list)
{
	long int 	i;
	char		*new_str;

	if (ft_iscontained('-', list->set))
	{
		new_str = (char*)malloc(sizeof(char));
		list->aux = ft_hyphen(str, new_str, list);
		free(new_str);
		/**
		if (list->conversion == 'd' || list->conversion == 'i')
		{
			new_str = (char*)malloc(sizeof(char));
			list->aux = ft_sign(list->aux, new_str, list);
			free(new_str);
		}
		**/
	}
	else
	{
		if (list->zero != '\0' && list->width > (long int)ft_strlen(str))
		{
			new_str = (char*)malloc(sizeof(char));
			list->aux = ft_zeros(str, new_str, list);
			free(new_str);
			/**if (list->conversion == 'd' || list->conversion == 'i')
			{
				new_str = (char*)malloc(sizeof(char));
				list->aux = ft_sign(list->aux, new_str, list);
				free(new_str);
			}
			**/
		}
		else
		{
			i = 0;
			new_str = (char*)malloc(sizeof(char));
			/**if (list->conversion == 'd' || list->conversion == 'i')
				list->aux = ft_sign(str, new_str, list);**/
			free(new_str);
			while (i < list->width - (long int)ft_strlen(str))
			{
				list->aux[i] = ' ';
				i++;
			}
			while (i < list->width)
			{
				list->aux[i] = *str;
				str++;
				i++;
			}
		}
	}
	list->len += list->width;
	return (list->aux);
}

t_struct	*ft_d_conversion(t_struct *list)
{
	long int	i;
	char		*str;

	i = 0;
	str = ft_itoa(va_arg(list->args, int));
	if (list->precision > list->width && list->precision > (long int)ft_strlen(str))
	{
		list->aux = (char*)malloc(sizeof(char));
		str = ft_put_precision_integers(str, list);
		free(list->aux);
		/**list->aux = (char*)malloc(sizeof(char));
		str = ft_sign(str, list->aux, list);
		free(list->aux);*/
		ft_putstr(str);
		list->len += list->precision;
	}
	else
	{
		if (list->width > (long int)ft_strlen(str))
		{
			if (list->precision > (long int)ft_strlen(str))
			{
				list->aux = (char*)malloc(sizeof(char));
				str = ft_put_precision_integers(str, list);
				free(list->aux);
				if (ft_iscontained('-', list->set))
				{
					list->aux = (char*)malloc(sizeof(char));
					str = ft_hyphen(str, list->aux, list);
					free(list->aux);
				}
				else
				{
					while (i < list->width - list->precision)
					{
						ft_putchar(' ');
						i++;
					}
				}
				ft_putstr(str);
				list->len += list->width;
			}
			else
			{
				list->aux = (char*)malloc(sizeof(char));
				str = ft_put_witdh(str, list);
				free(list->aux);
				ft_putstr(str);
			}
		}
		else
		{
			ft_putstr(str);
			list->len += ft_strlen(str);
		}
	}
	return (list);
}

t_struct	*ft_s_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;

	list->zero = '\0';
	str = va_arg(list->args, char*);
	list->aux = (char*)malloc(sizeof(char));
	str = ft_put_precision_chars(str, list);
	list->aux = NULL;
	free(list->aux);
	if (list->width > (long int)ft_strlen(str))
	{
		list->aux = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, list);
		list->aux = NULL;
		free(list->aux);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		list->len += ft_strlen(str);
	}
	return (list);
}

t_struct	*ft_c_conversion(t_struct *list)
{
	char		*str;

	str = (char*)malloc(sizeof(char));
	*str = va_arg(list->args, int);
	if (list->width > 1)
	{
		list->aux = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, list);
		ft_putstr(str);
		list->aux = NULL;
		free(list->aux);
	}
	else
	{
		ft_putchar(*str);
		list->len++;
	}
	str = NULL;
	free(str);
	return (list);
}

t_struct	*ft_conversion(t_struct *list)
{
	if (list->conversion == 'c')
		ft_c_conversion(list);
	if (list->conversion == 's')
		ft_s_conversion(list);
	if (list->conversion == 'd' || list->conversion == 'i')
		ft_d_conversion(list);
	return (list);
}

char		*get_number(t_struct *list, int i, char *nbr)
{
	int		j;

	j = 0;
	while (ft_isdigit(list->set[i]))
	{
		nbr[j] = list->set[i];
		i++;
		j++;
	}
	return (nbr);
}

t_struct	*ft_width(t_struct *list)
{
	int		i;
	int		j;
	char	*nbr;

	i = 0;
	j = 0;
	if (ft_iscontained('*', list->set))
		list->width = list->asterisk_width;
	else
	{
		while (list->set[i] != '\0')
		{
			if (list->set[i] == '.' || ft_isdigit(list->set[i]) == 1)
				break ;
			i++;
		}
		if (list->set[i] == '0')
		{
			list->zero = list->set[i];
			i++;
		}
		nbr = (char*)malloc(sizeof(char));
		get_number(list, i, nbr);
		if (nbr)
			list->width = (long int)ft_atoi(nbr);
		nbr = NULL;
		free(nbr);
	}
	return (list);
}

t_struct	*ft_precision(t_struct *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (list->asterisk_precision)
		list->precision = list->asterisk_precision;
	else
	{
		while (list->set[i] != '.')
			i++;
		i++;
		nbr = (char*)malloc(sizeof(char));
		get_number(list, i, nbr);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
		nbr = NULL;
		free(nbr);
	}
	return (list);
}

t_struct	*ft_asterisk(t_struct *list)
{
	int i;

	i = 0;
	while (list->set[i] != '.' && list->set[i] != '\0')
	{
		if (list->set[i] == '*')
			list->asterisk_width = va_arg(list->args, long int);
		i++;
	}
	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		while (list->set[i] != '\0')
		{
			if (list->set[i] == '*')
				list->asterisk_precision = va_arg(list->args, long int);
			i++;
		}
	}
	return (list);
}

void		ft_start(t_struct *list)
{
	if (ft_iscontained('*', list->set))
		ft_asterisk(list);
	if (ft_iscontained('.', list->set))
		ft_precision(list);
	ft_width(list);
	ft_conversion(list);
}

void		update_set(t_struct *list)
{
	int j;

	j = 0;
	while (ft_isalpha(list->format[list->i]) == 0)
	{
		list->set[j] = list->format[list->i];
		list->i++;
		j++;
	}
	list->conversion = list->format[list->i];
	list->i++;
}

t_struct	*real_parser(t_struct *list)
{
	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] == '%' && list->format[list->i + 1] == '%')
		{
			ft_putchar(list->format[list->i]);
			list->i = list->i + 2;
			list->len++;
		}
		if (list->format[list->i] == '%')
		{
			list->i++;
			list->set = (char*)malloc(sizeof(char));
			update_set(list);
			ft_start(list);
			free(list->set);
		}
		else
		{
			ft_putchar(list->format[list->i]);
			list->i++;
			list->len++;
		}
	}
	return (list);
}

int			parser(t_struct *list)
{
	if (!(ft_iscontained('%', list->format)))
	{
		ft_putstr((char *)list->format);
		return (ft_strlen(list->format));
	}
	else
		real_parser(list);
	return (list->len);
}

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
	free(list);
	printf("\n%d\n", len_outpt);
	return (len_outpt);
}

int			main(void)
{
	ft_printf("son %-88.6d cosas", 12345);
	return (0);
}
