/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:28 by ipizarro          #+#    #+#             */
/*   Updated: 2019/12/11 16:37:31 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		update_str(char *str, unsigned int n)
{
	unsigned int	i;
	char			*ptr;

	i = BUFFER_SIZE - n;
	ptr = &str[n];
	ft_memcpy(str, ptr, i);
	str[i] = '\0';
}

char		*carve_line(char *str, int *newline_found)
{
	unsigned int	size;
	char			*cut;

	if (str == NULL)
		return (NULL);
	size = 0;
	*newline_found = 0;
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
	update_str(str, size + *newline_found);
	return (cut);
}

static int	check_error(int n)
{
	if (n < 0)
		return (-1);
	return (0);
}

int			process_buffer(char **line, char *buffer)
{
	char	*temp;
	char	*carved;
	int		newline_found;

	newline_found = 0;
	temp = *line;
	carved = carve_line(buffer, &newline_found);
	*line = ft_strjoin(*line, carved);
	free(temp);
	free(carved);
	return (newline_found);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[4096];
	int			n;
	int			newline_found;

	if (!buffer[fd])
	{
		buffer[fd] = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1));
		buffer[fd][0] = 0;
	}
	newline_found = 0;
	*line = ft_strdup("");
	while (!newline_found)
	{
		while (buffer[fd][0])
		{
			if (process_buffer(line, buffer[fd]))
				return (1);
		}
		if ((n = read(fd, buffer[fd], BUFFER_SIZE)) <= 0)
			return (check_error(n));
		buffer[fd][n] = 0;
	}
	return (0);
}
