# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 16:12:11 by ccliffor          #+#    #+#              #
#    Updated: 2018/07/10 16:39:44 by ccliffor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-- PROGRAM --#
NAME	= fdf
SRCS	= fdf.c

#	-- Compiler, libs, flags
INCLUDES	= -I libft/libft.h
WFLAGS		= -Wall -Werror -Wextra
CC			= gcc
CFLAGS		= $(WFLAGS) $(INCLUDES)

#	-- Colours
COLOUR_CLEAR	= \033[0m
COLOUR_CYAN		= \033[01;36m
COLOUR_GREEN	= \033[00;32m

.PHONY: clean fclean re

#-- RULES --#
all: $(NAME)

#	-- Core Program
$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $< -o $@ 
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE COMPILED$(COLOUR_CLEAR)\n"

#	-- General Rules
clean:
	@rm -f $(NAME)
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE REMOVED$(COLOUR_CLEAR)"

re: fclean all
