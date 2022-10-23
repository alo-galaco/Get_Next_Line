/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:20:43 by flcristi          #+#    #+#             */
/*   Updated: 2022/10/23 18:23:49 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char	*s);
char	*save_line(char	*s);
char	*save_rest(char	*s);

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	new_line = save_line(str[fd]);
	if (!new_line)
		return (NULL);
	str[fd] = save_rest(str[fd]);
	return (new_line);
}

char	*read_line(int fd, char	*s)
{
	char	*buffer;
	int		rd;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(s, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		if (s == NULL)
		{
			s = malloc(1);
			s[0] = '\0';
		}
		s = ft_strjoin_free(s, buffer);
		if (!s)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (s);
}

char	*save_line(char	*s)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_rest(char	*s)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if ((s[i] == '\n' && s[i + 1] == '\0') || !s[i])
		return (free(s), NULL);
	rest = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		rest[j++] = s[i++];
	rest [j] = '\0';
	free(s);
	return (rest);
}
