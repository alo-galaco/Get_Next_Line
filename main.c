/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:24:24 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/18 01:41:51 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open("poema.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed\n");
		return (1);
	}
	i = 3;
	while (i-- > 0)
	{
		str = get_next_line (fd);
		printf("%s\n", str);
		free (str);
	}
	close(fd);
	return (0);
}