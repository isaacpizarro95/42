/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:46:53 by ipizarro          #+#    #+#             */
/*   Updated: 2019/11/29 15:47:20 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*lines_split(char const *s, char c)
{
	char	*line;
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		line[i] = s[i];
		i++;
	}
	line = ft_strdup(line);
	return (line);
}
