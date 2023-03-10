/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:18:54 by tvo               #+#    #+#             */
/*   Updated: 2023/01/16 14:50:15 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	ft_bzero(void *ptr, size_t count)
{
	size_t	i;

	if (!ptr)
		return ;
	i = 0;
	while (i < count)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t sz)
{
	void	*ptr;

	if (sz && count * sz / sz != count)
		return (NULL);
	ptr = malloc(count * sz);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * sz);
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		sizetotal;
	int		i;
	int		j;

	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (sizetotal + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		else
			str++;
	}
	return (0);
}
