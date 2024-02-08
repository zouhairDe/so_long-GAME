# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 21:25:38 by zouddach          #+#    #+#              #
#    Updated: 2024/02/06 19:00:03 by zouddach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
BNAME=so_long_bonus
LDFLAGS = -lncurses
SRC= SRC/main.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c Utils/ft_checker.c ft_printf/ft_printf.c ft_printf/ft_printf_nbr.c \
		ft_printf/ft_printf_putadr.c ft_printf/ft_printf_putchar.c ft_printf/ft_printf_puthex.c ft_printf/ft_printf_putstr.c \
		ft_printf/ft_printf_putunsigned.c Utils/libc_functions1.c Utils/ft_init_data.c Utils/ft_copy_map.c Utils/libc_functions2.c \
		Utils/ft_map_checker1.c Utils/counters.c Utils/game_sumilation.c Utils/keys_handler.c Utils/mover.c

BONUSSRC= BONUS/SRC/main.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c BONUS/Utils/ft_checker.c ft_printf/ft_printf.c ft_printf/ft_printf_nbr.c \
		ft_printf/ft_printf_putadr.c ft_printf/ft_printf_putchar.c ft_printf/ft_printf_puthex.c ft_printf/ft_printf_putstr.c \
		ft_printf/ft_printf_putunsigned.c BONUS/Utils/libc_functions1.c BONUS/Utils/ft_init_data.c BONUS/Utils/ft_copy_map.c BONUS/Utils/libc_functions2.c \
		BONUS/Utils/ft_map_checker1.c BONUS/Utils/counters.c BONUS/Utils/game_sumilation.c BONUS/Utils/keys_handler.c BONUS/Utils/mover.c BONUS/Utils/ft_itoi.c \
		BONUS/Utils/enemy_checker.c

OBG= $(SRC:.c=.o)
BONUSOBG= $(BONUSSRC:.c=.o)
FLAGS= -Wall -Wextra -Werror
MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit
CC= cc
RM= rm -f

%.o: %.c so_long.h 
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

ZOUDDACH_SO_LONG="\n${RED}███████╗${RESET}░${GREEN}█████╗${RESET}░${YELLOW}██╗${RESET}░░░${YELLOW}██╗${MAGENTA}██████╗${RESET}░${MAGENTA}██████╗${RESET}░░${BLUE}█████╗${RESET}░░${CYAN}█████╗${RESET}░${CYAN}██╗${RESET}░░${CYAN}██╗\n${RED}╚════██║${GREEN}██╔══██╗${YELLOW}██║${RESET}░░░${YELLOW}██║${MAGENTA}██╔══██╗██╔══██╗${BLUE}██╔══██╗${CYAN}██╔══██╗██║${RESET}░░${CYAN}██║\n${RESET}░░${RED}███╔═╝${GREEN}██║${RESET}░░${GREEN}██║${YELLOW}██║${RESET}░░░${YELLOW}██║${MAGENTA}██║${RESET}░░${MAGENTA}██║██║${RESET}░░${MAGENTA}██║${BLUE}███████║${CYAN}██║${RESET}░░${CYAN}╚═╝███████║\n${RED}██╔══╝${RESET}░░${GREEN}██║${RESET}░░${GREEN}██║${YELLOW}██║${RESET}░░░${YELLOW}██║${MAGENTA}██║${RESET}░░${MAGENTA}██║██║${RESET}░░${MAGENTA}██║${BLUE}██╔══██║${CYAN}██║${RESET}░░${CYAN}██╗██╔══██║${RED}\n███████╗${GREEN}╚█████╔╝${YELLOW}╚██████╔╝${MAGENTA}██████╔╝██████╔╝${BLUE}██║${RESET}░░${BLUE}██║${CYAN}╚█████╔╝██║${RESET}░░${CYAN}██║\n${RED}╚══════╝${RESET}░${GREEN}╚════╝${RESET}░░${YELLOW}╚═════╝${RESET}░${MAGENTA}╚═════╝${RESET}░${MAGENTA}╚═════╝${RESET}░${BLUE}╚═╝${RESET}░░${BLUE}╚═╝${RESET}░${CYAN}╚════╝${RESET}░${CYAN}╚═╝${RESET}░░${CYAN}╚═╝\n						's s0_long is ready${RED}"

$(NAME): $(OBG)
	@$(CC) $(FLAGS) $(OBG) -o $(NAME) $(MLX_FLAGS)
	@echo ${ZOUDDACH_SO_LONG}

bonus: $(BONUSOBG)
	@$(CC) $(FLAGS) $(BONUSOBG) -o $(BNAME) $(MLX_FLAGS) $(LDFLAGS)
	@echo ${ZOUDDACH_SO_LONG}

clean:
	@$(RM) $(OBG) $(BONUSOBG)
	@echo "$(RED)Cleaning .o files...$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@echo "$(RED)Cleaning executable...$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re