/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:28 by ipizarro          #+#    #+#             */
/*   Updated: 2019/12/05 19:53:47 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	move_str_left(char *str, unsigned int n)
{
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
	unsigned int	i;
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
	if (!(cut = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		cut[i] = str[i];
		i++;
	}
	cut[size] = 0;
	move_str_left(str, size + 1);
	return (cut);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[4096];
	char		*temp;
	char		*carved;
	int			n;
	int			newline_found;

	if (!buffer[fd])
	{
		buffer[fd] = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1));
		buffer[fd][0] = 0;
		buffer[fd][BUFFER_SIZE] = 0;
	}
	newline_found = 0;
	*line = ft_strdup("");
	while (!newline_found)
	{
		while (buffer[fd][0])
		{
			temp = *line;
			carved = carve_line(buffer[fd], &newline_found);
			*line = ft_strjoin(*line, carved);
			free(temp);
			free(carved);
			if (newline_found)
				return (1);
		}
		n = read(fd, buffer[fd], BUFFER_SIZE);
		if (n == 0)
		{
			return (0);
		}
		if (n < 0)
		{
			return (-1);
		}
	}
	return (0);
}