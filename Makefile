# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 12:24:40 by dmota-ri          #+#    #+#              #
#    Updated: 2026/01/19 15:34:46 by dmota-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c

OBJ = $(SRC:.c=.o)

#BONUS = ft_lists_1_bonus.c ft_lists_2_bonus.c

#B_OBJ = $(BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.h
LIBFT_NAME = $(LIBFT_DIR)/libft.a

LIBMLX_DIR = minilibx-linux
LIBMLX = $(LIBMLX_DIR)/mlx.h
LIBMLX_NAME = $(LIBMLX_DIR)/libmlx_Linux.a

MLX_FLAGS = -L$(LIBMLX_DIR) -lmlx_Linux -lXext -lX11 -lm

INC = -I$(LIBMLX_DIR) -I$(LIBFT_DIR) -I.

CFLAGS = #-Wall -Wextra -Werror -DNO_MAIN
CC = cc

#	CFLAGS = -Wall -Wextra -Werror -I includes

RM = rm -f

all: $(LIBMLX_DIR) minilibx $(NAME)

$(LIBMLX_DIR):
	@if [ ! -d "$(LIBMLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(LIBMLX_DIR); \
	fi

$(LIBMLX_NAME):
	make -C $(LIBMLX_DIR)

minilibx: $(LIBMLX_DIR)
#	make -C $(LIBMLX_DIR)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_NAME) $(LIBMLX_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME)

# $(LIBFT_NAME)

#	cc -Wall -Wextra -Werror -DNO_MAIN -I minilibx-linux/mlx.a -I libft -I . *.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	rm -rf minilibx-linux

re: fclean all

#bonus: $(B_OBJ) $(NAME)
#	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I . $(OBJ) -o $(B_OBJ)
#	ranlib $(NAME) 

.PHONY: all clean fclean re minilibx