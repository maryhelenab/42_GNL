/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbuque <malbuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/28 19:22:30 by malbuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int	find_nl(char *str)
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

void	update(char *buff, char *src)
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

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	char		*strtemp;
	int			readret;
	int			index_nl;

	//Read is necessary to check if the file is exists or is valid.
	if ((read(fd, NULL, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strlen(buff) == 0)
	{
		readret = read(fd, buff, BUFFER_SIZE);
		buff[readret] = '\0';
	}
	index_nl = find_nl(buff);
	if (index_nl >= 0)
	{
		str = ft_substr(buff, 0, index_nl + 1);
		update(buff, (buff + index_nl + 1));
	}
	else
	{
		strtemp = ft_substr(buff, 0, ft_strlen(buff));
		update(buff, (buff + ft_strlen(buff)));
		readret = 1;
		index_nl = -1;
		while (ft_strlen(buff) == 0 && readret > 0 && index_nl < 0)
		{
			readret = read(fd, buff, BUFFER_SIZE);
			index_nl = find_nl(buff);
			if (index_nl < 0 && readret > 0)
			{
				str = ft_strjoin (strtemp, ft_substr(buff, 0, ft_strlen(buff)));
				update(buff, (buff + ft_strlen(buff)));
			}
			else if (index_nl >= 0)
			{
				str = ft_strjoin (strtemp, ft_substr(buff, 0, index_nl + 1));
				update(buff, (buff + index_nl + 1));
			}
			//printf("%d // %d // %d \n", ft_strlen(buff), readret, index_nl);
		}
	}
	return (str);
}

int	main(void)
{
	int		fd;

	/* Abrindo um arquivo em modo leitura. Se este arquivo não existir no diretório local, ocasionara em erro na abertura.. */
	fd = open ("Texto.txt", O_RDONLY);
	if (fd < 0)
		fprintf (stderr, "Erro : %s\n", strerror(errno));
	char	*str;
	/*str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);*/
	str = get_next_line(fd);
	printf("%s", str);
	while (ft_strlen(str)>0)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	/*Fechando o arquivo*/
	close(fd);
	return (0);
}
