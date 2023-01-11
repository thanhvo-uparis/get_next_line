/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:18:25 by tvo               #+#    #+#             */
/*   Updated: 2023/01/11 14:04:17 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *new_line(char *stash)
{
	int size;
	int i;
	char *res;

	i = 0;
	size = ft_findline(stash);
	res = malloc(sizeof(char) * size + 1);
	while (stash[i] && i < size)
	{
		if (stash[i] == '\n')
			break ;
		res[i] = stash[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	static char *stash;
	char *line;
	char *tmp;
	int		num_read;

	while (ft_strchr(buf, '\n'))
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read == -1)
			return (NULL);
		line = ft_join(stash, buf);
		if (stash)
			free(stash);
		stash = line;
		//buf           stash
		//hello         hello
		//Hello_Doll    Hello_Doll
	}

	tmp = new_line(stash);
	// stash = new_stash;
	return (tmp);
}

// char *new_stash(char *stash)
// {
// 	int count = 0;
// 	int i = 0;
// 	char *new;

// 	while (stash[i])
// 	{
// 		if [i] == '\n'
// 			break;
// 		i++;
// 	}

// 	i++;
// 	while (stash[i])
// 	{
// 		count++;
// 		i++;
// 	}

// 	new = malloc cout + 1

// 	i--;
// 	int j = 0;
// 	while (stash[i])
// 	{
// 		new[j] = stash[i];
// 		count--;
// 		i--;
// 	}

// 	return (stash);
// }


// char *get_new_stch(stash, position)
// {
// 	int len;
// 	int size;
// 	char *str;

// 	if(stash == NULL)
// 		return (NULL);

// 	len = ft_strlen(stash);
// 	size = len - position;
// 	*str = malloc(sizeof(char) * (size + 1))

// 	i = 0;
// 	while(i < size)
// 	{
// 		str[i] = stash[position + i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (stash);
// }

// void	get_next_line(int fd)
// {
// 	static char		*stash;
// 	// char			*buf;

// 	stash = get_line(fd);
// 	printf("%s\n", stash);
// }
int main()
{
	int fd;
	char *line;

	// /mnt/nfs/homes/tvo/Downloads/fd_file/test1.txt
	fd = open("t1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR!");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s\n", line);
	// while (line = get_next_line(fd) != NULL)
	// 	printf("%s", line);
	if (close(fd) == -1)
	{
		printf("Close is error!");
		return (1);
	}
}
