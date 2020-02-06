/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:53:18 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 18:24:48 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_hyphen(char *chain, t_struct *list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(chain))
	{
		ft_putchar(chain[i]);
		i++;
	}
	while (i < (size_t)list->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (list);
}

char	*ft_put_precision(char *str, t_struct *list)
{
	long int	i;
	char		*new_str;

	i = 0;
	new_str = (char*)malloc(sizeof(char));
	while (i < list->precision)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
	free(new_str);
}

char		*aux_zeros(char *str, size_t size)
{
	size_t	i;
	size_t	j;
	char	*new_char;

	i = 0;
	j = 0;
	new_char = NULL;
	if (size <= ft_strlen(str))
		return (str);
	else
	{
		while (i < size - ft_strlen(str))
		{
			new_char[i] = '0';
			i++;
		}
		while (str)
		{
			new_char[i] = str[j];
			i++;
			j++;
		}
		return (new_char);
	}
}

char		*ft_zeros(char *str, t_struct *list)
{
	size_t	size;

	if (list->asterisk)
		size = list->asterisk;
	else
	{
		if (list->precision)
			size = list->precision;
		else
			size = list->width;
	}
	return (aux_zeros(str, size));
}

t_struct	*ft_s_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;

	str = va_arg(list->args, char*);
	if (list->precision < (long int)ft_strlen(str))
		str = ft_put_precision(str, list);
	if (list->width > (long int)ft_strlen(str))
	{
		if (ft_iscontained('-', list->set))
			ft_hyphen(str, list);
		else
		{
			i = 0;
			j = 0;
			while (i < (list->width - (long int)ft_strlen(str)))
			{
				ft_putchar(' ');
				i++;
			}
			while (i < list->width)
			{
				ft_putchar(str[j]);
				i++;
				j++;
			}
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
	long int	i;
	char		*str;

	str = (char*)malloc(sizeof(char));
	i = 0;
	*str = va_arg(list->args, int);
	if (list->width > 1)
	{
		if (ft_iscontained('-', list->set))
			ft_hyphen(str, list);
		else
		{
			while (i < list->width - 1)
			{
				ft_putchar(' ');
				i++;
			}
			ft_putchar(*str);
		}
		list->len += list->width;
	}
	else
	{
		ft_putchar(*str);
		list->len++;
	}
	free(str);
	return (list);
}

t_struct	*ft_conversion(t_struct *list)
{
	if (list->conversion == 'c')
		ft_c_conversion(list);
	if (list->conversion == 's')
		ft_s_conversion(list);
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
	char	*nbr;

	i = 0;
	if (ft_iscontained('*', list->set))
		list->width = list->asterisk;
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
		nbr = (char*)malloc(sizeof(char) * ft_strlen(list->set));
		nbr = get_number(list, i, nbr);
		if (nbr == NULL)
			return (list);
		else
			list->width = ft_atoi(nbr);
		free(nbr);
	}
	return (list);
}

t_struct	*ft_precision(t_struct *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		i++;
		nbr = (char*)malloc(sizeof(char) * ft_strlen(list->set));
		nbr = get_number(list, i, nbr);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
		free(nbr);
	}
	if (ft_iscontained('*', list->set))
		list->asterisk = va_arg(list->args, long int);
	return (list);
}

void		ft_start(t_struct *list)
{
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

int			parser(t_struct *list)
{
	if (!(ft_iscontained('%', list->format)))
	{
		ft_putstr((char *)list->format);
		return (ft_strlen(list->format));
	}
	else
	{
		while (list->format[list->i] != '\0')
		{
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
	}
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
	printf("\n%d", len_outpt);
	return (len_outpt);
}

int			main(void)
{
	ft_printf("hola pedazo de %8.0s hombres", "buenos");
	return (0);
}
