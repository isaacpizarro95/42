/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:53:18 by ipizarro          #+#    #+#             */
/*   Updated: 2020/02/06 22:15:19 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hyphen(char *chain, char *new_chain, t_struct *list)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(chain))
	{
		new_chain[i] = chain[i];
		i++;
	}
	while (i < (size_t)list->width)
	{
		new_chain[i] = ' ';
		i++;
	}
	return (new_chain);
}

char		*ft_zeros(char *str, char *new_str, t_struct *list)
{
	long int i;

	i = 0;
	if (ft_iscontained('.', list->set))
		return (str);
	else	
	{
		while (i < list->width - (long int)ft_strlen(str))
		{
			new_str[i] = '0';
			i++;
		}
		while (i < list->width)
		{
			new_str[i] = str[i];
			i++;
		}
		return (new_str);
	}
}

char		*ft_put_precision(char *str, char *new_str, t_struct *list)
{
	long int	i;

	i = 0;
	while (i < list->precision)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char		*ft_put_witdh(char *str, char *new_str, t_struct *list)
{
	long int 	i;
	long int	j;
	char		*new_chain;

	if (list->zero != '\0' && list->width > (long int)ft_strlen(str))
	{
		new_chain = (char*)malloc(sizeof(char));
		new_str = ft_zeros(str, new_chain, list);
		free(new_chain);
	}
	else
	{
		if (ft_iscontained('-', list->set))
		{
			new_chain = (char*)malloc(sizeof(char));
			new_str = ft_hyphen(str, new_chain, list);
			free(new_chain);
		}
		else
		{
			i = 0;
			j = 0;
			while (i < (list->width - (long int)ft_strlen(str)))
			{
				new_str[i] = ' ';
				i++;
			}
			while (i < list->width)
			{
				new_str[i] = str[j];
				i++;
				j++;
			}
		}
	}
	list->len += list->width;
	return (new_str);
}

t_struct	*ft_d_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;
	char		*new_str;

	str = ft_itoa(va_arg(list->args, int));
	if (list->width > (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, new_str, list);
		free(new_str);
	}
	if (ft_iscontained('.', list->set) && list->precision < (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_precision(str, new_str, list);
		free(new_str);
	}
	else
	{
		ft_putstr(str);
		list->len += ft_strlen(str);
	}
	return (list);
}

t_struct	*ft_s_conversion(t_struct *list)
{
	long int	i;
	long int	j;
	char		*str;
	char		*new_str;

	str = va_arg(list->args, char*);
	if (ft_iscontained('.', list->set) && list->precision < (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_precision(str, new_str, list);
		free(new_str);
	}
	if (list->width > (long int)ft_strlen(str))
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, new_str, list);
		ft_putstr(str);
		free(new_str);
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
	char		*new_str;

	i = 0;
	str = (char*)malloc(sizeof(char));
	*str = va_arg(list->args, int);
	if (list->width > 1)
	{
		new_str = (char*)malloc(sizeof(char));
		str = ft_put_witdh(str, new_str, list);
		ft_putstr(str);
		free(new_str);
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
	if (list->conversion == 'd')
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
	printf("\n%d\n", len_outpt);
	return (len_outpt);
}

int			main(void)
{
	ft_printf("hola pedazo de %-8d hombres", 12345);
	return (0);
}
