# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgranja <cgranja@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:01:01 by ebarguil          #+#    #+#              #
#    Updated: 2022/11/08 16:54:40 by cgranja          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

INC		=	includes

C		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I $(INC)
CDEP	=	-MMD
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

LIB		=	-L ./Libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm

vpath %.c srcs
vpath %.c srcs/parsing
vpath %.c srcs/graphical

#dans SRC pensez a mute le main G(graphical_launch.c) ou P(main.c) selon les besoins

SRC		=	srcs/graphical/gr_closefree.c \
			srcs/graphical/gr_render.c \
			srcs/graphical/gr_readkey.c \
			srcs/graphical/gr_movekey.c \
			srcs/graphical/gr_move_speed.c \
			srcs/graphical/gr_movemap_int.c \
			srcs/graphical/gr_mlx_start.c \
			srcs/graphical/gr_minimap.c \
			srcs/graphical/gr_init_struct.c \
			srcs/graphical/gr_3drays_print.c \
			srcs/graphical/gr_3drays_calcul.c \
			srcs/graphical/gr_distance.c \
			srcs/graphical/gr_init_text.c \
			srcs/graphical/gr_init_player.c \
			srcs/main.c \
			srcs/parsing/ft_check_name.c \
			srcs/parsing/ft_fill_col.c \
			srcs/parsing/ft_isdigit_cub.c \
			srcs/parsing/ft_parsing.c \
			srcs/parsing/ft_read_data.c \
			srcs/parsing/ft_retouch.c \
			srcs/parsing/ft_save_elems.c \
			srcs/parsing/ft_save_map.c \
			srcs/parsing/ft_verify_close_map.c \
			srcs/parsing/utils.c \
		

OBJ		=	$(SRC:srcs/%.c=objs/%.o)
DEP		=	$(SRC:srcs/%.c=objs/%.d)

all			:	libft obj $(NAME)

bonus		:	libft obj $(NAME)

libft		:
				$(MAKE) -C Libft

-include $(DEP)

$(NAME)		:	$(OBJ) ./Libft/libft.a
				make -C minilibx-linux
				$(C) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

obj			:
				@if [ ! -d "./objs" ]; then\
					echo "mkdir -p objs";\
					mkdir -p objs;\
				fi
				@if [ ! -d "./objs/parsing" ]; then\
					echo "mkdir -p objs/parsing";\
					mkdir -p objs/parsing;\
				fi
				@if [ ! -d "./objs/graphical" ]; then\
					echo "mkdir -p objs/graphical";\
					mkdir -p objs/graphical;\
				fi
				@echo ""

objs/%.o	:	%.c
				$(C) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs/parsing
				$(RM) objs/graphical
				$(RM) objs
				make -C Libft clean
				make -C minilibx-linux clean

fclean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs/parsing
				$(RM) objs/graphical
				$(RM) objs
				$(RM) $(NAME)
				make -C Libft fclean
				make -C minilibx-linux clean

fsa			:	fclean obj $(OBJ)
				make -C Libft
				make -C minilibx-linux
				$(C) $(CFLAGS) $(CFA) -o $(NAME) $(SRC) $(LIB)

re			:	fclean all

n			:
				@echo ""
				norminette Libft
				@echo ""
				norminette srcs
				@echo ""
				norminette includes
				@echo ""

.PHONY		:	all bonus clean fclean re n