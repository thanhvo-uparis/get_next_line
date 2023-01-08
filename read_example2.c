/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_example2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:34:36 by tvo               #+#    #+#             */
/*   Updated: 2023/01/08 22:37:07 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
#define BUF_SIZE 4

int main()
{
	int fd;
	size_t num_read;
	char buf[BUF_SIZE + 1];

	fd = open("/mnt/nfs/homes/tvo/Downloads/fd_file/test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR!");
		return (1);
	}
	while (num_read = read(fd, buf, BUF_SIZE))
	{
		printf("nombre d'octets: %ld\n", num_read);
		printf("%s\n", buf);
	}
	printf("nombre d'octets: %ld \n", num_read);
	if (close(fd) == -1)
	{
		printf("Close is error!");
		return (1);
	}
}
