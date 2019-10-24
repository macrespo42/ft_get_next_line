/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:48:49 by macrespo          #+#    #+#             */
/*   Updated: 2019/10/24 15:54:09 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 6000
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> /* debug */

char	*ft_strchr(const char *s, int c);
char	*ft_stridup(const char *s1, int start);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
#endif
