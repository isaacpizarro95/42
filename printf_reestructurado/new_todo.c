/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_todo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:38:33 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/17 00:32:53 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_aux_hexadecimal(int k, char *str, t_struct *list)
{
	int		i;
	int		j;
	char	*hexadecimal;

	j = 0;
	if (list->conversion == 'x')
		hexadecimal = "0123456789abcdef";
	else
		hexadecimal = "0123456789ABCDEF";
	while (k >= 16)
	{
		i = k % 16;
		str[j] = hexadecimal[i];
		k = k / 16;
		j++;
	}
	str[j] = hexadecimal[k];
	return (str);
}

t_struct	*ft_base_hexadecimal(int k, t_struct *list)
{
	int		j;
	char	*str;
	char	*aux;

	str = (char*)malloc(sizeof(char));
	aux = (char*)malloc(sizeof(char));
	j = 0;
	ft_aux_hexadecimal(k, str, list);
	while (j < ft_strlen(str))
	{
		aux[j] = str[ft_strlen(str) - 1 - j];
		j++;
	}
	list->str = aux;
	free(str);
	free(aux);
	return (list);
}

t_struct	*ft_sign(t_struct *list)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(char));
	if (ft_iscontained('-', list->str))
	{
		list->sign = 1;
		while (list->str[i + 1] != '\0')
		{
			str[i] = list->str[i + 1];
			i++;
		}
		list->str = str;
		return(list);
	}
	free(str);
	return(list);
}

t_struct	*ft_zeros(t_struct *list)
{
	long int i;

	i = (long int)ft_strlen(list->str);
	while (i < list->width)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(list->str);
	return (list);
}

t_struct	*ft_spaces(t_struct *list)
{
	long int i;

	i = (long int)ft_strlen(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(list->str);
	return (list);
}

t_struct	*ft_hyphen(t_struct *list)
{
	long int i;

	i = (long int)ft_strlen(list->str);
	ft_putstr(list->str);
	while (i < list->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (list);
}

t_struct	*ft_put_witdh(t_struct *list)
{
	if (ft_iscontained('-', list->set))
		ft_hyphen(list);
	else if (list->zero == '0' && !(ft_iscontained('.', list->set)))
		ft_zeros(list);
	else
		ft_spaces(list);
	list->len += list->width;
	return (list);
}

t_struct	*ft_aux_put_precision_integers(long int i, t_struct *list)
{
	char		*str;
	long int	j;
	long int	k;

	j = 0;
	k = 0;
	str = (char*)malloc(sizeof(char));
	while (i < list->precision)
	{
		str[j] = '0';
		j++;
		i++;
	}
	while (list->str[k])
	{
		str[j] = list->str[k];
		j++;
		k++;
	}
	str[j] = '\0';
	list->str = str;
	ft_put_witdh(list);
	return (list);
}

t_struct	*ft_put_precision_integers(t_struct *list)
{
	long int	i;
	long int	j;

	list->zero = '\0';
	i = (long int)ft_strlen(list->str);
	j = 0;
	if (list->width > list->precision)
		ft_aux_put_precision_integers(i, list);
	else
	{
		while (j < list->precision - i)
		{
			ft_putchar('0');
			j++;
		}
		ft_putstr(list->str);
		list->len += list->precision;
	}
	return (list);
}

char		*ft_put_precision_chars(char *new_str, t_struct *list)
{
	long int	i;
	long int	j;

	i = (long int)ft_strlen(list->str);
	j = 0;
	if (list->precision < (long int)ft_strlen(list->str))
	{
		while (j < list->precision)
		{
			new_str[j] = list->str[j];
			j++;
		}
	}
	return (new_str);
}

t_struct	*ft_p_conversion(t_struct *list)
{
	list->zero = '\0';
	list->str = (char*)va_arg(list->args, void*);
	if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len += (long int)ft_strlen(list->str);
	}
	return (list);
}

t_struct	*ft_int_conversion(t_struct *list)
{
	unsigned int i;

	if (list->conversion == 'u')
		list->str = ft_itoa(va_arg(list->args, long unsigned int));
	else if (list->conversion == 'x' || list->conversion == 'X')
	{
		i = va_arg(list->args, unsigned long int);
		ft_base_hexadecimal(i, list);
	}
	else
		list->str = ft_itoa(va_arg(list->args, long int));
	ft_sign(list);
	if (list->precision > (long int)ft_strlen(list->str))
		ft_put_precision_integers(list);
	else if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len += ft_strlen(list->str);
	}
	return (list);
}

t_struct	*ft_s_conversion(t_struct *list)
{
	char	*new_str;

	list->zero = '\0';
	list->str = va_arg(list->args, char*);
	if (list->precision < (long int)ft_strlen(list->str))
	{
		if (list->precision == 0)
			list->str = NULL;
		else
		{
			new_str = (char*)malloc(sizeof(char));
			list->str = ft_put_precision_chars(new_str, list);
			free(new_str);
		}
	}
	if (list->width > (long int)ft_strlen(list->str))
		ft_put_witdh(list);
	else
	{
		if (list->str)
		{
			ft_putstr(list->str);
			list->len += ft_strlen(list->str);
		}
	}
	return (list);
}

t_struct	*ft_c_conversion(t_struct *list)
{
	list->zero = '\0';
	*list->str = va_arg(list->args, int);
	if (list->width > 1)
		ft_put_witdh(list);
	else
	{
		ft_putstr(list->str);
		list->len++;
	}
	return (list);
}

t_struct	*ft_conversion(t_struct *list)
{
	list->str = (char*)malloc(sizeof(char));
	if (list->conversion == 'c')
		ft_c_conversion(list);
	else if (list->conversion == 's')
		ft_s_conversion(list);
	else if (list->conversion == 'd' || list->conversion == 'i')
		ft_int_conversion(list);
	else if (list->conversion == 'u')
		ft_int_conversion(list);
	else if (list->conversion == 'x' || list->conversion == 'X')
		ft_int_conversion(list);
	else if (list->conversion == 'p')
		ft_p_conversion(list);
	//free(list->str);
	return (list);
}

t_struct	*ft_aux_widht(int i, int j, t_struct *list)
{
	char	*nbr;

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
	while (ft_isdigit(list->set[i]))
	{
		nbr[j] = list->set[i];
		i++;
		j++;
	}
	if (nbr)
		list->width = (long int)ft_atoi(nbr);
	free(nbr);
	return(list);
}

t_struct	*ft_width(t_struct *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_iscontained('*', list->set))
		list->width = list->asterisk_width;
	else
		ft_aux_widht(i, j, list);
	return (list);
}

t_struct	*ft_aux_precision(t_struct *list)
{
	char	*nbr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (list->set[i] != '.')
		i++;
	i++;
	nbr = (char*)malloc(sizeof(char));
	while (ft_isdigit(list->set[i]))
	{
		nbr[j] = list->set[i];
		i++;
		j++;
	}
	if (nbr == NULL)
		list->precision = 0;
	else
		list->precision = (long int)ft_atoi(nbr);
	free(nbr);
	return (list);
}

t_struct	*ft_precision(t_struct *list)
{
	if (list->asterisk_precision)
		list->precision = list->asterisk_precision;
	else
		ft_aux_precision(list);
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

t_struct	*ft_start(t_struct *list)
{
	if (ft_iscontained('*', list->set))
		ft_asterisk(list);
	if (ft_iscontained('.', list->set))
		ft_precision(list);
	ft_width(list);
	ft_conversion(list);
	return (list);
}

t_struct	*update_set(t_struct *list)
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
	return (list);
}

t_struct	*real_parser(t_struct *list)
{
	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] == '%')
		{
			if (list->format[list->i] == '%' && list->format[list->i + 1] == '%')
			{
				ft_putchar(list->format[list->i]);
				list->i = list->i + 2;
				list->len++;
			}
			else
			{
				list->i++;
				list->set = (char*)malloc(sizeof(char));
				update_set(list);
				ft_start(list);
				free(list->set);
			}
		}
		ft_putchar(list->format[list->i]);
		list->i++;
		list->len++;
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
	int		i = 30;
	void	*ptr = &i;

	ft_printf("son %12X cosas", 30);
	//getchar();
	return (0);
}
