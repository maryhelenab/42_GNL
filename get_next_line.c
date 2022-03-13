/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryhelen <maryhelen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/13 22:15:47 by maryhelen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			readret;

	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	readret = read(fd, buff, BUFFER_SIZE);
	while (readret > 0)
	{
		buff[readret] = '\0';
		printf("\n buff result: %s \n",buff);
		readret = read(fd, buff, BUFFER_SIZE);
	}
	return (buff);
}

int	main(void)
{
	int		fd;

	/* Abrindo um arquivo em modo leitura. Se este arquivo não existir no diretório local, ocasionara em erro na abertura.. */
	fd = open ("Texto.txt", O_RDONLY);
	if (fd < 0)
		fprintf (stderr, "Erro : %s\n", strerror(errno));
	get_next_line(fd);
	char	*str;
	str = get_next_line(fd);
	printf("Printf Main: %s\n", str);
	/*Fechando o arquivo*/
	close(fd);
	return (0);
}
