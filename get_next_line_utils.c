/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:01:08 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/23 22:15:08 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ptr;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	while (!s1 && !s2)
		return (NULL);
	ptr = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[n1])
	{
		ptr[n1] = s1[n1];
		n1++;
	}
	while (s2[n2])
	{
		ptr[n1] = s2[n2];
		n2++;
		n1++;
	}
	ptr[n1] = '\0';
	return (free(s1), ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	ptr;

	ptr = c;
	if (!s)
		return (NULL);
	while (*s != ptr)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}