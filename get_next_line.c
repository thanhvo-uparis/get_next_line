/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:18:25 by tvo               #+#    #+#             */
/*   Updated: 2023/01/13 14:51:38 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free(char *stash, char *buf)
{
	char	*tmp;

	tmp = ft_join(stash, buf);
	if (stash)
		free(stash);
	return (tmp);
}

char *get_line(char *stash)
{
	int size;
	int i;
	char *res;

	if(ft_strlen(stash) == 0)
		return (NULL);
	i = 0;
	size = ft_findline(stash);
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

	if(sizetotal == 0)
		return (NULL);
	pos = ft_findline(str);
	nb_extract = sizetotal - (pos - 1);
	res = ft_calloc(nb_extract + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str && str[pos] != '\0')
		res[i++] = str[pos++];
	res[nb_extract] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char	*buf;
	static char	*stash;
	char	*line;
	int		num_read;
	int		size_stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	while (1)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read == -1)
			return (NULL);
		if (num_read == 0 && stash == NULL)
		{
			free(buf);
			return (NULL);
		}
		line = ft_join(stash, buf);
		if (stash)
			free(stash);
		stash = line;
		if (ft_strchr(stash, '\n'))
			break ;
		if (num_read == 0)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	free(line);
	line = get_line(stash);
	size_stash = ft_strlen(stash);
	stash = extract_line(stash, size_stash);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("newline.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("ERROR!");
// 		return (1);
// 	}

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	if (close(fd) == -1)
// 	{
// 		printf("Close is error!");
// 		return (1);
// 	}
// }
