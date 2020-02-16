/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 04:50:20 by isaacpizarr       #+#    #+#             */
/*   Updated: 2020/02/17 00:16:17 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>

int     main(void)
{
    int     i = 40;
    void    *ptr = &i;

    printf("son %p cosas\n", ptr);
    return (0);
}
