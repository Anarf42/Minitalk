# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 12:41:48 by anruiz-d          #+#    #+#              #
#    Updated: 2025/02/19 01:49:35 by anruiz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

DIR_SRCS	:= srcs
DIR_OBJS	:= .objs
DIR_INCL	:= include

SRC_FILES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c	 \
			 	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
				GNL/get_next_line.c GNL/get_next_line_utils.c ft_printf/ft_printf.c \
				ft_printf/ft_printf_utils.c

SRC_BONUS_FILES =	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \

OBJ_FILES	= $(addprefix $(DIR_OBJS)/, $(SRC_FILES:.c=.o))
OBJ_BONUS_FILES = $(addprefix $(DIR_OBJS)/, $(SRC_BONUS_FILES:.c=.o))
SRC_FILES_PATH	=$(addprefix $(DIR_SRCS)/, $(SRC_FILES))
LIST_INCS	= libft.h get_next_line.h ft_printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE	= -I $(DIR_INCL)
AR = ar rcs
RM = rm -rf
MKDIR = mkdir -p

# ------ COLORINCHIS --------
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[33m
COLOR_GREEN = \033[32m
COLOR_CYAN = \033[36m

all: $(NAME) bonus

$(NAME): $(DIR_OBJS) $(OBJ_FILES)
			@echo "$(COLOR_YELLOW)Creando la libreria $(NAME) ...$(COLOR_RESET)"
			@echo "$(COLOR_CYAN)Archivando $(words $(OBJ_FILES)) archivos objeto en $(NAME) ...$(COLOR_RESET)"
			@$(AR) $(NAME) $(OBJ_FILES)
			@echo "$(COLOR_GREEN)¡Librería $(NAME) creada con éxito! $(COLOR_RESET)"

bonus: $(DIR_OBJS) $(OBJ_BONUS_FILES)
	@$(AR) $(NAME) $(OBJ_BONUS_FILES)
	@echo "$(COLOR_GREEN)¡Bonus compilados con éxito!$(COLOR_RESET)"

$(DIR_OBJS):
		@$(MKDIR) $(DIR_OBJS)
			
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
			@mkdir -p $(dir $@)
			@echo "$(COLOR_CYAN)Compilando $(notdir $<)...$(COLOR_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
