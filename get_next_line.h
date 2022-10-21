/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:53:20 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/18 16:57:27 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*****************************
 *-- Check BUF_SIZE define --*
 ****************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*****************************
 *-- Utils + main function --*
 ****************************/

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
void	ft_substr(char *buf);

#endif
