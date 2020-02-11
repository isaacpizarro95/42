/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:59:34 by isaacpizarr       #+#    #+#             */
/*   Updated: 2020/02/10 23:57:22 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int     main(void)
{
    int     i;
    int     j;
    int     k;
    int     l;
    int     x;
    char    *abc;
    char    *str;

    i = 0;
    x = 0;
    abc = "ABCDEFGHIJKLMNOPQRSTUWXYZ";
    str = NULL;
    while (x != 32)
    {
        j = rand () % strlen(abc);
        k = rand () % strlen(abc);
        l = rand () % strlen(abc);
        if (i >= 3)
        {
            printf("%s\n", str);
            str = NULL;
            free(str);
            i = 0;
        }
        if (str == NULL)
            str = (char*)malloc(sizeof(char));
        str[i] = abc[j];
        i++;
        str[i] = abc[k];
        i++;
        str[i] = abc[l];
        i++;
        l++;
        k++;
        x++;
    }
    free(str);
    return (0);
}