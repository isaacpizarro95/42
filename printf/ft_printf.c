/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:56:21 by ipizarro          #+#    #+#             */
/*   Updated: 2020/03/09 19:00:05 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_struct	*list;
	int			len_outpt;

	if (!(list = malloc(sizeof(t_struct))))
		return (-1);
	list->format = ft_strdup(format);
	va_start(list->args, format);
	len_outpt = parser(list);
	list->format = NULL;
	list->i = 0;
	list->len = 0;
	va_end(list->args);
	free(list);
	return (len_outpt);
}

int main ()
{
    int i = (printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    int j = (ft_printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    j = (ft_printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    j = (ft_printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    j = (ft_printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    j = (ft_printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    j = (ft_printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    j = (ft_printf("%c %d %p %x %s %u %X %% %c %d %p %x %s %u %X %% %c %d %p %x %s %u\n", 'a', 57957,
    "dfhhsh", 58578, "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578,
    "Napoleon", -16637, 86798, 'a', 57957, "dfhhsh", 58578, "Napoleon", -16637));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
    i = (printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    j = (ft_printf("%x %X %x %X %x %X %p %p %p %p %u %x %X %p %X %x %u %p\n", 4242, 4242, 4242 ,4242, 4242,
    4242, "4242", "4242", "4242", "4242", 4242, 4242, 4242, "4242", 4242, 4242, 4242, "4242"));
    printf("printf = %d\nft_printf = %d\n\n", i, j);
}

