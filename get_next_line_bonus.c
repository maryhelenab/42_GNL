/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbuque <malbuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:33 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/30 19:07:00 by malbuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			str = ft_strjoin (strtemp, buff[fd]);
		}
		update(buff[fd]);
	}
	return (str);
}
