/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:34:14 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/18 11:31:45 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    char    *array;
	int		i;
	int		n;

	n = nmemb * size;
    if (n / nmemb != size)
        return (NULL);
    array = malloc(n);
    if (!array)
	{
        return (NULL);
	}
	i = 0;
	while (i < n)
    {
        array[i] = '\0';
		i++;
    }
    return (array);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(line) + ft_strlen(buf) + 1, 1);
	if (!str)
		return (NULL);
	if (line)
	{
		while (line[j])
		{
			if (line[j] == '\n')
			{
				free(line);
				return (str);
			}
			str[i] = line[j];
			i++;
			j++;
		}
		free(line);
	}
	j = 0;
	while (buf[j])
	{
		str[i] = buf[j];
		if (buf[j] == '\n')
			return (str);
		i++;
		j++;
	}
	return (str);
}

void	ft_substr(char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	if (!buf[i])
		return ;
	i++;
	j = 0;
	while (buf[i])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	buf[j] = '\0';
}
