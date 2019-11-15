/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:50:40 by marvin            #+#    #+#             */
/*   Updated: 2019/11/15 13:50:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    **ft_split(char const *s, char c)
{
    char **new_strs;
    char *str;
    int i;

    i = 0;
    while (*s)
    {
        while (*s != c)
        {
            *str = *s;
            str++;
            s++;
        }
        if (*s == c)
        {
            new_strs[i] = str; 
            i++;
        }
        s++;
    }
    return (new_strs);
}

int     main(void)
{
    char character;
    char *s;

    s = "vaca laca perraca";
    character = 'c';
    printf("%s\n", ft_split(argv[1], character));
    return (0);
}