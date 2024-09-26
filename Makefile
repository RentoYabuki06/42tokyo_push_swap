# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 13:21:51 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/26 19:01:25 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/required_functions/push.c \
		./srcs/required_functions/reverse_rotate.c \
		./srcs/required_functions/rotate.c \
		./srcs/required_functions/swap.c \
		./srcs/fill_stack.c \
		./srcs/main.c \
		./srcs/free.c \
		./srcs/init.c \
		./srcs/error.c \
		./srcs/ft_is_sorted.c \
		./srcs/sort_small.c \
		./srcs/sort_large.c \

OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ./srcs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
