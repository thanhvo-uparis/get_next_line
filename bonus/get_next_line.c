/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:18:25 by tvo               #+#    #+#             */
/*   Updated: 2023/01/16 14:50:29 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stack, char *buf)
{
	char	*tmp;

	tmp = ft_join(stack, buf);
	free(stack);
	return (tmp);
}

char	*extract_line(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(stack) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stack[i])
		line[j++] = stack[i++];
	free(stack);
	return (line);
}

char	*get_line(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] && stack[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *stack)
{
	char	*buf;
	int		num_read;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	num_read = 1;
	while (num_read > 0)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[num_read] = '\0';
		stack = ft_free(stack, buf);
		if (ft_strchr(stack, '\n'))
			break ;
	}
	free(buf);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = extract_line(stash);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("2-otarie.txt", O_RDONLY);
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
