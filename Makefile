# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 12:49:27 by mavicent          #+#    #+#              #
#    Updated: 2023/06/08 16:36:48 by mavicent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	= 	./libraries/libft
LIBFT	=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX	=	$(MINILIBX_PATH)/libmlx.a

GET_NEXT_LINE_PATH = ./libraries/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_PATH)/get_next_line.a

FT_PRINTF_PATH = ./libraries/ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

SOURCES_FILES	=	so_long.c \
					draw.c\
					start.c\
					read_map.c\
					map_validate.c\
					player_update.c\
					gameplay.c\
					close_game.c\
					flood_fill.c

SOURCES_DIR	=	src

HEADER		=	$(SOURCES_DIR)/so_long.h

SOURCES		=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS		=	$(SOURCES:.c=.o)

NAME		=	so_long

CC			=	cc
RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS	=	-L. -lXext -L. -lX11

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: 			$(NAME)

$(NAME): 		$(LIBFT) $(MINILIBX) $(GET_NEXT_LINE) $(FT_PRINTF) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(GET_NEXT_LINE) $(FT_PRINTF) $(MLXFLAGS) -o $(NAME)

$(LIBFT): 
			$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):	
			$(MAKE) -C $(MINILIBX_PATH)

$(GET_NEXT_LINE):
			$(MAKE) -C $(GET_NEXT_LINE_PATH)

$(FT_PRINTF):
			$(MAKE) -C $(FT_PRINTF_PATH)

clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MINILIBX_PATH) clean
			$(MAKE) -C $(GET_NEXT_LINE_PATH) clean
			$(MAKE) -C $(FT_PRINTF_PATH) clean
			$(RM) $(OBJECTS)

fclean: 	clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft minilibx bonux
