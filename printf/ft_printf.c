/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:26:07 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/03 22:04:24 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_number(t_list *list, int i)
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

t_list	*ft_width(t_list *list)
{
	int		i;
	char	*nbr;

	i = 0;
	while (list->set[i] != '.' || ft_isdigit(list->set[i]) == 0
	|| list->set[i] != '\0')
		i++;
	if (list->set[i] = '0')
	{
		list->zero = list->set[i];
		i++;
	}
	nbr = get_number(list, &i);
	if (nbr == NULL)
		return (list);
	else
		list->width = ft_atoi(nbr);
	return (list);
}

char	*ft_hyphen(char *chain, t_list *list)
{
	int		i;
	char	*new_chain;

	i = 0;
	if (list->width <= ft_strlen(chain))
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

char	*ft_zeros(char *str, t_list *list)
{
	int		i;
	int		j;
	int		size;
	char	*new_str;

	i = 0;
	j = 0;
	if (!(list->precision) && list->zero == '0')
		size = list->width;
	else
		size = list->precision;
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

t_list	*ft_precision(t_list *list)
{
	int		i;
	char	*nbr;

	i = 0;
	if (ft_iscontained('.', list->set))
	{
		while (list->set[i] != '.')
			i++;
		i++;
		nbr = get_number(list, &i);
		if (nbr == NULL)
			list->precision = 0;
		else
			list->precision = ft_atoi(nbr);
	}
	if (ft_iscontained('*', list->set))
		list->asterisk = va_arg(list->args, long int);
	return (list);
}

void	ft_start(t_list *list)
{
	list->i++;
	ft_precision(list);
	ft_width(list);
}

void	update_set(t_list *list)
{
	int i;
	int j;

	i = list->i + 1;
	j = 0;
	while (!(ft_isalpha(list->format[i])))
	{
		list->set[j] = list->format[i];
		i++;
		j++;
	}
	list->conversion = list->format[i];
}

int		parser(t_list *list)
{
	if (!(ft_iscontained('%', list->format)))
	{
		ft_putstr(list->format);
		return (ft_strlen(list->format));
	}
	else
	{
		while (list->format[list->i] != '\0')
		{
			if (list->format[list->i] == '%')
			{
				update_set(list);
				ft_start(list);
			}
			ft_putchar(list->format[list->i]);
			list->i++;
			list->len++;
		}
	}
	return (list->len);
}

int		ft_printf(const char *format, ...)
{
	t_list	*list;
	int		len_outpt;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (-1);
	list->format = format;
	list->i = 0;
	list->len = 0;
	if (format)
	{
		va_start(list->args, format);
		len_outpt = parser(list);
		va_end(list->args);
	}
	free(list);
	return (len_outpt);
}

int		main(void)
{
	printf("hola %s hombre", "buen");
	return (0);
}
