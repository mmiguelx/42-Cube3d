# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 00:48:42 by mpernia-          #+#    #+#              #
#    Updated: 2020/02/25 03:17:05 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cube3d

INC_DIR		=	./includes/
LIBFT_DIR	=	$(INC_DIR)libft
MINIL_DIR	=	$(INC_DIR)minilibx_O
INC			=	$(addprefix -I , $(MINIL_DIR))

CC			=	gcc
FLAGS		=	-c -Wall -Wextra -Werror
EXTRA_FLAG	=	-lmlx -framework OpenGL -framework AppKit

SRCS_DIR	=	./sources/
SRCS		=	$(addprefix $(SRCS_DIR), $(shell find $(SRCS_DIR)\
					-name "*.c" | rev | cut -d '/' -f1 | rev))

OBJS_DIR	=	./objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(shell find $(OBJS_DIR)\
					-name "*.o" | rev | cut -d '/' -f1 | rev))
OBJECTS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))



all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -I$(SRCS_DIR) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Adding libft..."
	@make -C $(LIBFT_DIR)
	@echo "Adding mlx lib..."
	@make -C $(MINIL_DIR)
	@echo "Compiling objects..."
	$(CC) $(INC) main.c $(OBJS) -l ft -L $(LIBFT_DIR) $(EXTRA_FLAG) -o $(NAME)
	@echo "Done."

.PHONY: all clean fclean

debug:
	$(CC) $(INC) main.c $(SRCS) -l ft -L $(LIBFT_DIR) $(EXTRA_FLAG) -g -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning cube3d objects..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINIL_DIR) clean
	@rm -f $(NAME)
	@echo "Cleaning cube3d.a"

re: fclean all
