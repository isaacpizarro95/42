/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:45:14 by ipizarro          #+#    #+#             */
/*   Updated: 2019/11/27 16:10:27 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char *ptr;

	ptr = dest;
	while(*src != '\0')
	{
		if (*src)
			*dest = *src;
		else
			*dest = '\0';
		dest++;
		src++;
	}
	*dest = '\0';
	printf("%s\n", dest);
	printf("%s\n", ptr);
	return (ptr);
}

int		main(void)
{
	printf("%s\n", ft_strcpy("hola", "clos"));
	return (0);
}
