/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:52:04 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/15 17:50:43 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		str_gnl(char **line)
{
	int		i;

}

int		get_next_line(int fd, char **line)
{
	if (fd == 1)
		str_gnl();
	else
		files_gnl();
	return (0);
}
