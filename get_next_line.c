/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:18:25 by tvo               #+#    #+#             */
/*   Updated: 2023/01/09 21:53:48 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_new_stch(stash, position)
{
	int len;
	int size;
	char *str;

	if(stash == NULL)
		return (NULL);

	len = ft_strlen(stash);
	size = len - position;
	*str = malloc(sizeof(char) * (size + 1))

	i = 0;
	while(i < size)
	{
		str[i] = stash[position + i];
		i++;
	}
	str[i] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	char	*tmp;
	char buf[BUFFER_SIZE];
	int byte_read;
	int position;

	// byte_read = read(fd, buf, BUFFER_SIZE);
	// if (byte_read == -1)
	// {
	// 	free(buf);
	// 	return (NULL);
	// }



	//
	while(ft_strchr(stash, '\n', &position) == 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if(byte_read <= 0)
				break;
		line = ft_join(stash, buf);
		if(stash)
			free(stash);
		stash = line;
	}

	printf("%s %d", stash, position);

	// 3 - line = get_line(stash, position); // abcdef\n
	// 4 - tmp = get_new_stch(stash, position)
	if(stash)
		free(stash);
	stash = tmp;


	return (line);
}

// void	read_file(int fd)
// {
// 	char *buf[BUFFER_SIZE];
// 	int byte_read;

// 	byte_read = read(fd, buf, BUFFER_SIZE);
// 	if (byte_read == -1)
// 	{
// 		free(buf);
// 		return (NULL);
// 	}

// }

int main()
{
	int fd;
	size_t num_read;
	char buf[BUFFER_SIZE];

	// /mnt/nfs/homes/tvo/Downloads/fd_file/test1.txt
	fd = open("t1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR!");
		return (1);
	}

	get_next_line(fd);

	if (close(fd) == -1)
	{
		printf("Close is error!");
		return (1);
	}
}
