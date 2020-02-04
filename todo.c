/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:53:18 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/04 21:14:38 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hyphen(char *chain, t_struct *list)
{
	int		i;
	char	*new_chain;

	i = 0;
	new_chain = NULL;
	if (list->width <= (long int)ft_strlen(chain))
		return (chain);
	else
	{
		while (chain[i] != '\0')
		{
			new_chain[i] = chain[i];
			i++;
		}
		while (i < list->width)
		{
			new_chain[i] = ' ';
			i++;
		}
		return (new_chain);
	}
}

char		*aux_zeros(char *str, size_t size)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = NULL;
	if (size <= ft_strlen(str))
		return (str);
	else
	{
		while (i < size - ft_strlen(str))
		{
			new_str[i] = '0';
			i++;
		}
		while (str)
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
		return (new_str);
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
	char		*new_str;

	str = va_arg(list->args, char*);
	new_str = NULL;
	if (list->width > (long int)ft_strlen(str))
	{
		if (ft_iscontained('-', list->set))
			ft_putstr(ft_hyphen(str, list));
		else
		{
			i = 0;
			j = 0;
			while (i < list->width - (long int)ft_strlen(str))
			{
				new_str[i] = ' ';
				ft_putchar(new_str[i]);
				i++;
			}
			while (str)
			{
				new_str[i] = str[j];
				ft_putchar(new_str[i]);
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
	char		c;
	char		*str;

	str = NULL;
	c = va_arg(list->args, int);
	if (list->width > 1)
	{
		if (ft_iscontained('-', list->set))
			ft_putstr(ft_hyphen(str, list));
		else
		{
			i = 0;
			while (i < list->width - 1)
			{
				str[i] = ' ';
				i++;
			}
			str[i] = c;
			ft_putstr(str);
		}
		list->len += list->width;
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
	return (list);
}
/**
char		*get_number(t_struct *list, int i)
{
	int		j;
	char	*nbr;

	j = 0;
	nbr = NULL;
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
		while (list->set[i] != '.' || ft_isdigit(list->set[i]) == 0
		|| list->set[i] != '\0')
			i++;
		if (list->set[i] == '0')
		{
			list->zero = list->set[i];
			i++;
		}
		nbr = get_number(list, i);
		if (nbr == NULL)
			return (list);
		else
			list->width = ft_atoi(nbr);
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
		nbr = get_number(list, i);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
	}
	if (ft_iscontained('*', list->set))
		list->asterisk = va_arg(list->args, long int);
	return (list);
}
**/
void		ft_start(t_struct *list)
{
	/**ft_precision(list);
	ft_width(list);**/
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
				list->set = (char*)malloc(sizeof(char) * ft_strlen(list->format));
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
	ft_printf("hola pedazo de %08s hombres, %-7s", "buenos", "putos");
	return (0);
}
