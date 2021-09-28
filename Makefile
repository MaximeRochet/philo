# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrochet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 14:23:35 by mrochet           #+#    #+#              #
#    Updated: 2021/09/28 18:05:14 by mrochet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

NAME = philo

SRCS_NAME = action.c\
		   	main.c\
	  		mutex.c\
	   		parse.c\
			time.c

LIB_NAME = philo.h

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS_PATH = srcs
LIB_PATH = ./includes
OBJS_PATH = .objs

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

RM		=	rm -f
CC		=	gcc
#FSAN	=	-g -fsanitize=address
CFLAGS	=	-Wall -Werror -Wextra
	

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(LIB)
			@mkdir -p $(OBJS_PATH)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB_PATH)
			@printf "$(ERASE)$(YELLOW)$@$(END)"

all:
		@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@printf "$(ERASE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(LIB_PATH)
	@echo "$(BOLD)$(GREEN)Compilation $(NAME) Succes !$(END)"



clean :
		@rm -rf $(OBJS_PATH)
		@echo "$(RED)Clean $(NAME) Succes !$(END)"

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) fclean -C ./libft
			@echo "$(RED)Fclean $(NAME) Succes !$(END)"


re:		fclean all clean compil_lib
