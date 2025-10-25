# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamorcil <gamorcil@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 20:59:27 by gamorcil          #+#    #+#              #
#    Updated: 2025/10/25 13:22:16 by gamorcil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = so_long

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I./libft -I./ft_printf -I./gnl -I./minilibx-linux

# Archivos fuente
SRCS = main.c \
       check_map.c \
       set_map.c \
	   render_map.c \
	   prepare_game.c \
	   set_hooks.c \
	   images.c \
	   move.c \
	   flood_fill.c \
	   check_map_utils.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# Directorios de librerías
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
GNL_DIR = ./gnl
MLX_DIR = ./minilibx-linux

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Flags de linkeo
LDFLAGS = -L$(LIBFT_DIR) -lft \
          -L$(FT_PRINTF_DIR) -lftprintf \
          -L$(MLX_DIR) -lmlx \
          -L/usr/lib -lXext -lX11 -lm -lz

# Colores para output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Regla principal
all: $(NAME)

# Compilar librerías
$(LIBFT):
	@echo "$(GREEN)Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@echo "$(GREEN)Compilando ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR)

$(MLX):
	@echo "$(GREEN)Compilando minilibx...$(RESET)"
	@make -C $(MLX_DIR) CC="gcc -std=gnu99 -fcommon -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types -Wno-strict-prototypes -Wno-comment"

# Compilar archivos objeto
%.o: %.c so_long.h
	@echo "$(GREEN)Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Crear ejecutable
$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJS)
	@echo "$(GREEN)Creando ejecutable $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compilado exitosamente!$(RESET)"

# Limpiar archivos objeto
clean:
	@echo "$(RED)Limpiando archivos objeto...$(RESET)"
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean

# Limpiar todo
fclean: clean
	@echo "$(RED)Limpiando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

# Recompilar todo
re: fclean all

# Compilar en modo debug (sin flags de error)
debug: CFLAGS = -g
debug: fclean $(NAME)
	@echo "$(GREEN)✓ $(NAME) compilado en modo DEBUG (sin flags)$(RESET)"

# Reglas que no son archivos
.PHONY: all clean fclean re debug
