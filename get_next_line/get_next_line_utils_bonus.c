/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:31 by ipizarro          #+#    #+#             */
/*   Updated: 2019/12/07 15:57:51 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	s;

	s = 0;
	while (str[s])
		s++;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		s2++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(substr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		substr[i] = s[i + start];
		i += 1;
	}
	substr[i] = '\0';
	return (substr);
}
