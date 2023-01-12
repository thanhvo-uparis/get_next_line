/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:18:25 by tvo               #+#    #+#             */
/*   Updated: 2023/01/12 17:42:03 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *stash)
{
	int size;
	int i;
	char *res;

	i = 0;
	size = ft_findline(stash);
	// if (size == 0)
	// 	return (NULL);
	//size--;
	res = ft_calloc(size + 1, sizeof(char));
	while (stash[i] && i < size)
	{
		res[i] = stash[i];
		if (stash[i] == '\n')
			break ;
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

char *extract_line(char *str, int sizetotal)
{
	int	i;
	int nb_extract;
	int pos;
	char *res;

	pos = ft_findline(str);
	nb_extract = sizetotal - pos;
	res = ft_calloc(nb_extract + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str && str[pos] != '\0')
		res[i++] = str[pos++];
	res[nb_extract] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	static char	*stash;
	char	*line;
	int		num_read;
	int		size_stash;

	int i;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
	// buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	// if (!res)
	// 	return (NULL);
	while (1)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read == -1)
			return (NULL);
		line = ft_join(stash, buf);
		if (stash)
			free(stash);
		stash = line;
		if (ft_strchr(stash, '\n'))
			break ;
		if (num_read == 0)
			return (NULL);
	}
	line = get_line(stash);
	size_stash = ft_strlen(stash);
	stash = extract_line(stash, size_stash);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("t1.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("ERROR!");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);

// 	if (close(fd) == -1)
// 	{
// 		printf("Close is error!");
// 		return (1);
// 	}
// }
