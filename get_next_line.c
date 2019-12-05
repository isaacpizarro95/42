/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:28 by ipizarro          #+#    #+#             */
/*   Updated: 2019/12/05 19:53:40 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *ptr;

	ptr = dest;
	while (n > 0 && *src != '\0')
	{
		if (*src)
			*dest = *src;
		else
			*dest = '\0';
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (ptr);
}

void	move_str_left(char *str, unsigned int n)
{
	// char	*tmp;
	// tmp = ft_substr(str, n, BUFFER_SIZE + 1 - n);
	// str = ft_strncpy(str, tmp, BUFFER_SIZE + 1);
	// free(tmp);
	// ft_memcpy(str, &str[n], BUFFER_SIZE - n);
	// str[BUFFER_SIZE - n] = 0;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(str) < 2)
	{
		if (ft_strlen(str) == 1)
			str[0] = 0;
		return ;
	}
	while (i < n)
	{
		j = 0;
		while (str[j])
		{
			if (str[j + 1])
				str[j] = str[j + 1];
			else
				str[j] = 0;
			j++;
		}
		i++;
	}
}

char	*carve_line(char *str, int *newline_found)
{
	unsigned int	size;
	char			*cut;

	if (str == NULL)
		return (NULL);
	size = 0;
	while (str[size])
	{
		if (str[size] == '\n')
		{
			*newline_found = 1;
			break ;
		}
		size++;
	}
	cut = ft_substr(str, 0, size);
	move_str_left(str, size + 1);
	return (cut);
}

int		error_detection(int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	char		*carved;
	int			n;
	int			newline_found;

	buffer[BUFFER_SIZE] = '\0';
	newline_found = 0;
	*line = ft_strdup("");
	while (!newline_found)
	{
		while (buffer[0])
		{
			temp = *line;
			carved = carve_line(buffer, &newline_found);
			*line = ft_strjoin(*line, carved);
			free(temp);
			free(carved);
			if (newline_found)
				return (1);
		}
		if ((n = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (error_detection(n));
	}
	return (0);
}
