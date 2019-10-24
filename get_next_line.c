/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:52:04 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/24 17:39:33 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		reader(char **fat_buffer, int fd, char *buffer)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret && !(ft_strchr(*fat_buffer, '\n')))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (fd)
		{
			tmp = *fat_buffer;
			*fat_buffer = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	free(buffer);
	return (ret);
}

static char		*current_line(char **fat_buffer)
{
	char	*new_line;
	char	*tmp;
	int		i;

	tmp = ft_stridup(*fat_buffer, 0);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	free(*fat_buffer);
	*fat_buffer = ft_stridup(tmp, i + 1);
	if (!(new_line = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		new_line[i] = tmp[i];
		i++;
	}
	new_line[i] = '\0';
	free(tmp);
	return (new_line);
}

int				get_next_line(int fd, char **line)
{
	static char		*fat_buffer = NULL;
	char			*buffer;
	int				ret;

	if (fat_buffer == NULL)
		fat_buffer = (char*)ft_calloc(sizeof(char), 1);
	buffer = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	ret = reader(&fat_buffer, fd, buffer);
	*line = current_line(&fat_buffer);
	if (ret == 0)
	{
		free(fat_buffer);
		return (0);
	}
	return (1);
}
