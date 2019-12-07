/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:04:38 by isaacpizarr       #+#    #+#             */
/*   Updated: 2019/12/07 15:58:19 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		move_str_left(char *str, unsigned int n)
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

char		*carve_line(char *str, int *newline_found)
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

static int	check_error(int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*carved;
	int			n;
	int			newline_found;

	newline_found = 0;
	*line = ft_strdup("");
	while (!newline_found)
	{
		while (buffer[0])
		{
			carved = carve_line(buffer, &newline_found);
			*line = ft_strjoin(*line, carved);
			free(carved);
			if (newline_found)
				return (1);
		}
		if ((n = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (check_error(n));
	}
	return (0);
}