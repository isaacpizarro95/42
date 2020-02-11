/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cambio_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 00:25:29 by isaacpizarr       #+#    #+#             */
/*   Updated: 2020/02/11 01:26:28 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int cambio_base(int k, int base)
{
    int     output;
    int     j;
    char    *str;
    char    *aux;

    j = 0;
    str = (char*)malloc(sizeof(char));
    aux = (char*)malloc(sizeof(char));
    while (k >= base)
    {
        str[j] = (k % base) + 48;
        k = k / base;
        j++;
    }
    str[j] = k + 48;
    j = 0;
    while (j < ft_strlen(str))
    {
        aux[j] = str[ft_strlen(str) - 1 - j];
        j++;
    }
    output = ft_atoi(aux);
    free(str);
    free(aux);
    return (output);
}

int     main(void)
{
    printf("%d\n", cambio_base(768, 8));
    //getchar();
    return (0);
}
