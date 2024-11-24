# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:38:30 by ebarguil          #+#    #+#              #
#    Updated: 2022/10/06 20:25:47 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INC		=	includes

C		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I $(INC)
CDEP	=	-MMD
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

vpath %.c srcs

SRC		=	srcs/ft_atoi.c \
			srcs/ft_bzero.c \
			srcs/ft_contains.c \
			srcs/ft_gnl.c \
			srcs/ft_strdup_n.c \
			srcs/ft_strdup.c \
			srcs/ft_strlen.c \
			srcs/ft_strchr.c \
			srcs/ft_read_file.c \

OBJ		=	$(SRC:srcs/%.c=objs/%.o)
DEP		=	$(SRC:srcs/%.c=objs/%.d)

all			:	obj $(NAME)

-include $(DEP)

$(NAME)		:	$(OBJ)
				ar rcs $(NAME) $(OBJ)

obj			:
				@if [ ! -d "./objs" ]; then\
					echo "mkdir -p objs";\
					mkdir -p objs;\
				fi
				@echo ""

objs/%.o	:	%.c
				$(C) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs

fclean		:	clean
				$(RM) $(NAME)

fsa			:	fclean obj $(OBJ)
				$(C) $(CFLAGS) $(CDEP) $(CFA) -o $(NAME) $(SRC)

re			:	fclean all

.PHONY		:	all clean fclean re