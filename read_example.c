/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:57:05 by tvo               #+#    #+#             */
/*   Updated: 2023/01/08 22:34:27 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
#define BUF_SIZE 4096

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
	num_read = read(fd, buf, BUF_SIZE);
	buf[num_read] = '\0';
	printf("nombre d'octets: %ld \n", num_read);
	printf("%s", buf);
	if (close(fd) == -1)
	{
		printf("Close is error!");
		return (1);
	}
}
