/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_todo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:38:33 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/15 20:05:06 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
/**
char		*ft_put_witdh(char *str, t_struct *list)
{
	long int 	i;
	char		*new_str;

	if (ft_iscontained('-', list->set))
	{
		new_str = (char*)malloc(sizeof(char));
		list->aux = ft_hyphen(str, new_str, list);
		free(new_str);
		
		if (list->conversion == 'd' || list->conversion == 'i')
		{
			new_str = (char*)malloc(sizeof(char));
			list->aux = ft_sign(list->aux, new_str, list);
			free(new_str);
		}
		
	}
	else
	{
		if (list->zero != '\0' && list->width > (long int)ft_strlen(str))
		{
			new_str = (char*)malloc(sizeof(char));
			list->aux = ft_zeros(str, new_str, list);
			free(new_str);
			if (list->conversion == 'd' || list->conversion == 'i')
			{
				new_str = (char*)malloc(sizeof(char));
				list->aux = ft_sign(list->aux, new_str, list);
				free(new_str);
			}
			
		}
		else
		{
			i = 0;
			new_str = (char*)malloc(sizeof(char));
			if (list->conversion == 'd' || list->conversion == 'i')
				list->aux = ft_sign(str, new_str, list);
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
**/
t_struct	*ft_s_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;

	list->zero = '\0';
	str = va_arg(list->args, char*);
	if (ft_iscontained('.', list->set))
		str = ft_put_precision_chars(str, list);
	if (list->width > (long int)ft_strlen(str))
	{
		i = (long int)ft_strlen(str);
		if (ft_iscontained('-', list->set))
		{
			ft_putstr(str);
			while (i <= list->width)
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			while (i <= list->width)
			{
				ft_putchar(' ');
				i++;
			}
			ft_putstr(str);
		}
		list->len += list->width;
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
	char	c;
	int		i;

	i = 0;
	c = va_arg(list->args, int);
	if (list->width > 1)
	{
		if (ft_iscontained('-', list->set))
		{
			ft_putchar(c);
			while (i < list->width)
			{
				ft_putchar(' ');
				i++;
			}
			list->len += list->width;
		}
		else
		{
			while (i < list->width)
			{
				ft_putchar(' ');
				i++;
			}
			ft_putchar(c);
			list->len += list->width;
		}
	}
	else
	{
		ft_putchar(c);
		list->len++;
	}
	return (list);
}

t_struct	*ft_conversion(t_struct *list)
{
	if (list->conversion == 'c')
		ft_c_conversion(list);
	if (list->conversion == 's')
		ft_s_conversion(list);
	/**if (list->conversion == 'd' || list->conversion == 'i')
		ft_d_conversion(list);**/
	return (list);
}

t_struct	*ft_width(t_struct *list)
{
	int			i;
	int			j;
	char		*nbr;

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
		while (ft_isdigit(list->set[i]))
		{
			nbr[j] = list->set[i];
			i++;
			j++;
		}
		if (nbr)
			list->width = (long int)ft_atoi(nbr);
		free(nbr);
	}
	return (list);
}

t_struct	*ft_precision(t_struct *list)
{
	int			i;
	int			j;
	char		*nbr;

	i = 0;
	j = 0;
	if (list->asterisk_precision)
		list->precision = list->asterisk_precision;
	else
	{
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
	ft_printf("son %-*.*s cosas", 8, 2, "12345");
	//getchar();
	return (0);
}
