/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryhelen <maryhelen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/12 18:00:48 by maryhelen        ###   ########.fr       */
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
	static char	*txt;
	char		*buf;
	char		*ret;
	size_t		len;

	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return ERROR;
	len = 1;
	ret = NULL;
	buf = ft_strchr(txt, 'n');

	return (ret);
}

int	main(void)
{
	int		fd;
	char	*str;

	/* Abrindo um arquivo em modo leitura. Se este arquivo não existir no diretório local, ocasionara em erro na abertura.. */
	fd = open ("Texto.txt", O_RDONLY);
	if (fd < 0)
		fprintf (stderr, "Erro : %s\n", strerror(errno));
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	/*Fechando o arquivo*/
	close(fd);
	return (0);
}
