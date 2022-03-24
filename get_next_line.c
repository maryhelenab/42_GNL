/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryhelen <maryhelen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/24 21:14:18 by maryhelen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

void	temp(char *buff, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		buff[i] = src[i];
		i++;
	}
	buff[i] = '\0';
}

int	find_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	int			readret;
	int			i;

	//Read is necessary to check if the file is exists or is valid.
	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	readret = strlen(buff);
	if (!readret)
	{
		readret = read(fd, buff, BUFFER_SIZE);
		buff[readret] = '\0';
	}
	while (readret > 0)
	{
		i = find_n(buff);
		if (i >= 0)
		{
			str = ft_substr(buff, 0, i + 1);
			temp(buff, (buff + i + 1));
			break ;
		}
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
