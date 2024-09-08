# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 13:21:51 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/08 13:44:26 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/utils/push.c \
		./srcs/utils/reverse.c \
		./srcs/utils/rotate_rotate.c \
		./srcs/utils/swap.c \
		./srcs/init.c \
		./srcs/main.c \
		./srcs/sort_small.c \
		./srcs/sort_large.c \
		./srcs/support_func.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $@ $^
	ranlib $@

$(LIBFT):
	$(MAKE) -C ./srcs/libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./srcs/libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./srcs/libft/ fclean

re: fclean all