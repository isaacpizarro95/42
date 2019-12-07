/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaacpizarro95 <isaacpizarro95@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:24 by ipizarro          #+#    #+#             */
/*   Updated: 2019/12/07 15:58:04 by isaacpizarr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int     get_next_line(int fd, char **line);
void    move_str_left(char *str, unsigned int n);
char    *carve_line(char *str, int *newline_found);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_iscontained(char c, char *set);
int     error_detection(int n);

#endif
