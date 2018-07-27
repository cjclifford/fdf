# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 16:12:11 by ccliffor          #+#    #+#              #
#    Updated: 2018/07/27 15:02:12 by ccliffor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-- PROGRAM --#
NAME	= fdf
SRCDIR	= src/
SRCS	= $(SRCDIR)fdf.c $(SRCDIR)rotate.c $(SRCDIR)hooks.c $(SRCDIR)line_put_image.c \
			$(SRCDIR)read.c $(SRCDIR)draw.c $(SRCDIR)pixel_put_image.c $(SRCDIR)map.c \
			$(SRCDIR)colour.c
LIB	= libft/libft.a

#	-- Compiler, libs, flags
INCLUDE		= include/
HEADER		= $(INCLUDE)fdf.h
WFLAGS		= -Wall -Werror -Wextra -I
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
CC			= gcc
CFLAGS		= $(MLXFLAGS) $(WFLAGS) $(INCLUDE)

#	-- Colours
COLOUR_CLEAR	= \033[0m
COLOUR_CYAN		= \033[01;36m
COLOUR_GREEN	= \033[00;32m

.PHONY: clean fclean re

#-- RULES --#
all: $(NAME)

#	-- Core Program
$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $@
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE COMPILED$(COLOUR_CLEAR)\n"

#	-- General Rules
clean:
	@rm -f $(NAME)
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE REMOVED$(COLOUR_CLEAR)"

re: clean all
