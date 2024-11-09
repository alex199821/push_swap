# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <macbook@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 02:39:30 by macbook           #+#    #+#              #
#    Updated: 2024/11/09 03:14:42 by macbook          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(OFILES) -L$(LIBFT_DIR) -lft

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

.PHONY: all clean fclean re