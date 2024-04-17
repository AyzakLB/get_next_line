/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzaq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:08:42 by amarzaq           #+#    #+#             */
/*   Updated: 2024/01/09 19:27:19 by amarzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len_src;
	unsigned int	len_dst;
	unsigned int	i;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (len_dst >= size)
		return (len_src + size);
	if (len_dst < size - 1)
	{
		while (i < size - len_dst - 1 && src[i])
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	return (len_dst + len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	m;
	unsigned int	s_len;
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		m = 0;
	else if (s_len - start >= len)
		m = len;
	else
		m = s_len - start;
	str = malloc(sizeof(char) * (m + 1));
	if (!str)
		return (NULL);
	while (m-- && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
