/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:04:38 by isaacpizarr       #+#    #+#             */
/*   Updated: 2019/12/12 20:48:15 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (str[size] == '\n' || '\0')
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

static int	process_buffer(char **line, char *buffer)
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

static int	check_error(int n)
{
	if (n < 0)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			n;
	int			newline_found;

	if (fd < 0 || line == NULL)
		return (-1);
	newline_found = 0;
	*line = ft_strdup("");
	while (!newline_found)
	{
		while (buffer[0])
		{
			if (process_buffer(line, buffer))
				return (1);
		}
		if ((n = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (check_error(n));
		buffer[n] = 0;
	}
	free(buffer);
	return (0);
}
