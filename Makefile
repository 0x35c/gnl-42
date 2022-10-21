# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/10/14 21:48:13 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

SRCS = get_next_line.c get_next_line_utils.c

CC = @gcc

CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=1

OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: all clean

.PHONY: all clean fclean re
