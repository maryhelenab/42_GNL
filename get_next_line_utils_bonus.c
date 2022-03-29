/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbuque <malbuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:57:02 by malbuque          #+#    #+#             */
/*   Updated: 2022/03/29 22:08:44 by malbuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*Verificar o tamanho do elemento.*/
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i + (s && s[i] == '\n'));
}

/*Recebe duas strings e cria um destino para receber a concatenação de ambas. 
É feita a alocação de memória para o destino*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 && i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		dest[i] = s2[i - s1_len];
		i++;
	}
	if (s1)
		free(s1);
	dest[i] = '\0';
	return (dest);
}

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

void	update(char *buff)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = find_nl(buff);
	h = 0;
	while (buff[i] != '\0')
	{
		if (i > j)
			buff[h++] = buff[i];
		buff[i++] = '\0';
	}
}
