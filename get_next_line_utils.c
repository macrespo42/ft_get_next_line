/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:52:44 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/24 17:02:02 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	int			i;
	int			j;
	int			size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

void		*ft_calloc(size_t count, size_t size)
{
	char		*tab;
	size_t		i;

	if (!(tab = (char*)malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

char		*ft_stridup(const char *s1, int start)
{
	int			i;
	int			j;
	char		*s2;

	i = 0;
	j = start;
	while (s1[start])
	{
		start++;
		i++;
	}
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[j])
		s2[i++] = s1[j++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (!(s_new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- && s[start])
		s_new[i++] = s[start++];
	s_new[i] = '\0';
	return (s_new);
}
