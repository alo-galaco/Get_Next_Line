/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:24:24 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/23 22:14:26 by byoshimo         ###   ########.fr       */
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

	fd = open("teste", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed\n");
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		str = get_next_line (fd);
		printf("#%s", str);
		free (str);
		i++;
	}
	close(fd);
	return (0);
}