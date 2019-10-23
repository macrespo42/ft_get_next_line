/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:52:04 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/23 11:51:16 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		reader(char **readed, int fd, char *buffer)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > -1 && !(ft_strchr(*readed, '\n')))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (fd)
		{
			tmp = *readed;
			*readed = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	free(buffer);
}

int				get_next_line(int fd, char **line)
{
	static char		*readed = NULL;
	char			*buffer;

	buffer = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	readed = (char*)ft_calloc(sizeof(char), 1);
	reader(&readed, fd, buffer);
	return (0);
}
