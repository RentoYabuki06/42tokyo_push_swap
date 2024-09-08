# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 13:21:51 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/08 18:07:49 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/utils/push.c \
		./srcs/utils/reverse_rotate.c \
		./srcs/utils/rotate.c \
		./srcs/utils/swap.c \
		./srcs/init.c \
		./srcs/main.c \
		./srcs/sort_small.c \
		./srcs/sort_large.c \
		./srcs/support_functions.c 

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $@ $^
	ranlib $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
