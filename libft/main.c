/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:43:20 by szheng            #+#    #+#             */
/*   Updated: 2018/08/12 19:43:22 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(void)
{
  char  *line;
  int   fd1;

  fd1 = open("C:\Users\Isaac\Desktop\42cursus\42\libft\fd1.txt", O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  return (0);
}