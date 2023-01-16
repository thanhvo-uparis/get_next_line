/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:29:50 by tvo               #+#    #+#             */
/*   Updated: 2023/01/16 15:45:08 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
// # ifndef BUFFER_SIZE
// #define BUFFER_SIZE 5
// # endif
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef struct s_list
{
	int fd;
	static char *stack;
	t_list *p_next;
}	t_list;

int		ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
void	ft_bzero(void *ptr, size_t count);
void	*ft_calloc(size_t count, size_t sz);
int		ft_strchr(char *str, char c);

char	*ft_free(char *stack, char *buf);
char	*extract_line(char *stack);
char	*get_line(char *stack);
char	*read_file(int fd, char *stack);
char	*get_next_line(int fd);
#endif
