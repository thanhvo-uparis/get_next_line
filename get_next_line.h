/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:29:50 by tvo               #+#    #+#             */
/*   Updated: 2023/01/11 16:34:59 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 5

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>

char *get_line(char *stash);
char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t sz);
void	ft_bzero(void *ptr, size_t count);
int		ft_strchr(char *str, char c);
int	ft_findline(char *str);

#endif
