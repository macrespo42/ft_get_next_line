/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:52:04 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/18 10:15:29 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char **readed)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret && ft_strchr(*readed, '\n'))
	{
		ret  = read(fd, buffer, BUFFER_SIZE);
		if (fd)
		{
			buffer[ret] = '\0';
			tmp = *readed;
			if (!(readed = ft_strjoin(tmp, buffer)));
				return (NULL);
			free(tmp);
		}
	}
	free(buffer);
	return (*readed);
}

int		get_next_line(int fd, char **line)
{
	static char		**readed;
	char			*buffer;

	if (fd < 0)
		return (-1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (!(read_line(fd, buffer, &readed)))
		return (-1);

	return (0);
}
