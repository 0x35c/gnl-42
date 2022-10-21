/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:34:02 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/18 11:30:16 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_fd(int fd, char *buf)
{
	int	check_read;

	check_read = read(fd, buf, BUFFER_SIZE);
	if (check_read > 0)
	{
		buf[check_read] = '\0';
		return (check_read);
	}
	else
		return (0);
}

int	find_nl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	static int	check_read;

	line = NULL;
	while (!find_nl(buf))
	{
		if (buf[0] && !check_read)
			return (NULL);
		line = ft_strjoin(line, buf);
		check_read = read_fd(fd, buf);
		if (!check_read)
			break ;
	}
	if (find_nl(buf))
		line = ft_strjoin(line, buf);
	if (line && !line[0])
	{
		free(line);
		return (NULL);
	}
	ft_substr(buf);
	return (line);
}
/*
int main(void)
{
    int i;
    int fd;
	char	*str;

    fd = open("test3", 0);
    i = 0;
    while (i < 10)
    {
        //printf("Call %d:\n", i + 1);
		str = get_next_line(fd);
        printf("%s", str);
		free(str);
        //printf("---------\n");
        i++;
    }
    close(fd);
    return (0);
}*/
