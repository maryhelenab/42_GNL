/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbuque <malbuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/30 20:51:32 by malbuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	char		*strtemp;
	int			readret;
	int			index_nl;

	if ((fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	readret = 1;
	index_nl = -1;
	str = 0;
	while (readret > 0 && index_nl < 0)
	{
		if (buff[fd][0] == 0)
			readret = read(fd, buff[fd], BUFFER_SIZE);
		index_nl = find_nl(buff[fd]);
		if (readret > 0)
		{
			strtemp = str;
			str = ft_strline (strtemp, buff[fd]);
		}
		update(buff[fd]);
	}
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

/* Abrindo um arquivo em modo leitura. 
Se este arquivo não existir no diretório local, ocasionara em erro na abertura.. */
	fd = open ("Texto.txt", O_RDONLY);
	if (fd < 0)
		fprintf (stderr, "Erro : %s\n", strerror(errno));
	get_next_line(fd);
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
