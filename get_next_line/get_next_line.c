/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzaq <ayoubmarzaq1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:08:15 by amarzaq           #+#    #+#             */
/*   Updated: 2024/04/15 16:43:17 by amarzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	nl_pos(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	nl_trunc(char **container, int nl)
{
	char	*temp;

	temp = ft_strdup(*container + nl + 1);
	free(*container);
	*container = temp;
}

void	string_join(char **container, char *read_buffer)
{
	char	*temp;

	temp = ft_strdup(*container);
	free(*container);
	*container = ft_strjoin(temp, read_buffer);
	free(temp);
}

void	line_fill(int fd, char **container, char *read_buffer, char **line)
{
	ssize_t	bytes_read;
	size_t	cat_buff;

	cat_buff = BUFFER_SIZE;
	while (1)
	{
		bytes_read = read(fd, read_buffer, cat_buff);
		if (bytes_read <= 0)
			break ;
		read_buffer[bytes_read] = '\0';
		string_join(container, read_buffer);
		if (nl_pos(*container) > -1)
		{
			*line = ft_substr(*container, 0, nl_pos(*container) + 1);
			nl_trunc(container, nl_pos(*container));
			return ;
		}
	}
	if (bytes_read == -1 || !*container[0])
		*line = NULL;
	else if (container[0])
		*line = ft_strdup(*container);
	free(*container);
	*container = NULL;
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;
	char		*read_buffer;
	int			nl;
	size_t		cat_buff;

	cat_buff = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = malloc((cat_buff + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	if (!container)
		container = ft_strdup("");
	nl = nl_pos(container);
	if (nl > -1)
	{
		line = ft_substr(container, 0, nl + 1);
		nl_trunc(&container, nl_pos(container));
	}
	else
		line_fill(fd, &container, read_buffer, &line);
	free(read_buffer);
	return (line);
}

int main()
{
	char *str = get_next_line(2147483647);
	
}