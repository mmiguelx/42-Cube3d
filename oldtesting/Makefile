# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 00:48:42 by mpernia-          #+#    #+#              #
#    Updated: 2020/02/22 18:33:56 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	tresde

INC_DIR		=	./includes/
LIBFT_DIR	=	$(INC_DIR)libft
MINIL_DIR	=	$(INC_DIR)minilibx_O
INC			=	$(addprefix -I, $(LIBFT_DIR) $(MINIL_DIR))

CC			=	gcc
FLAGS		=	-c -Wall -Wextra -Werror
EXTRA_FLAG	=	-lmlx -framework OpenGL -framework AppKit

SRCS_DIR	=	./sources/
SRCS		=	$(addprefix $(SRCS_DIR), $(shell find $(SRCS_DIR)\
					-name "*.c" | rev | cut -d '/' -f1 | rev))

OBJS		=	$(SRCS:.c=.o)


all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@make -C $(MINIL_DIR)
	@echo "Creating objects..."
	$(CC) $(FLAGS) $(SRCS) -o $(SRCS:.c=.o)
	$(CC) $(INC) main.c $(OBJS) $(EXTRA_FLAG) -o tresde

.PHONY: all clean fclean

clean:
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning tresde objects..."
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINIL_DIR) clean
	@echo "Cleaning libftprintf.a"
	@rm -f $(NAME)
	@echo "Cleaning tresde.a"

re: fclean all
