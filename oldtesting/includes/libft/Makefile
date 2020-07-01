# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 15:23:10 by mpernia-          #+#    #+#              #
#    Updated: 2019/12/31 06:12:51 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a
SRCS	= 	ft_memcpy.c				\
			ft_isalpha.c			\
			ft_islower.c			\
			ft_isupper.c			\
			ft_memset.c				\
			ft_bzero.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strlen.c				\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strncmp.c			\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_isspace.c			\
			ft_calloc.c				\
			ft_strdup.c				\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_pow.c				\
			ft_strmapi.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_lstnew.c				\
			ft_lstadd_front.c		\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putcharntimes.c		\
			ft_ltoa.c				\
			ft_dechex.c

CC		= 	gcc
FLAGS	= 	-c -Wall -Wextra -Werror
LIB		= 	ar rc
RLIB	= 	ranlib
OBJS	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Reading libft sources..."
	@$(CC) $(FLAGS) $(SRCS)
	@echo "Building libft objects..."
	@$(LIB) $(NAME) $(OBJS)
	@echo "Compiling Libft..."
	@$(RLIB) $(NAME)

.PHONY: all clean fclean

clean:
	@echo "Cleaning libft objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning libft.a"
	@rm -f $(NAME)

re: fclean all
