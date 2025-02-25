# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 16:45:08 by anruiz-d          #+#    #+#              #
#    Updated: 2025/02/25 15:14:36 by anruiz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################################################
#				VARIABLES DEFINITIONS  				     		   #
####################################################################

# --- Project names --- #

NAMES		=	server
NAMEC		=	client
LIBFT		=	libft.a

# --- Directories ---#

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCL	:=	include

# --- Source files --- #

SRC_SERVER_FILE	=	server.c
SRC_CLIENT_FILE	=	client.c
SRC_SERVER_DIR	=	$(DIR_SRCS)/$(SRC_SERVER_FILE) 
SRC_CLIENT_DIR	=	$(DIR_SRCS)/$(SRC_CLIENT_FILE)

# --- Object files --- #

OBJ_SERVER_FILE	=	$(DIR_OBJS)/$(SRC_SERVER_FILE:.c=.o)
OBJ_CLIENT_FILE	=	$(DIR_OBJS)/$(SRC_CLIENT_FILE:.c=.o)

# --- Compiler and tools --- #

CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
INCLUDE	=	-I $(DIR_INCL)
AR		=	ar
RM		=	rm -rf
MKDIR	=	mkdir -p

####################################################################
#							COLORS DEFINITIONS	  		 		   #
####################################################################

COLOR_RESET	=	\033[0m
COLOR_GREEN	=	\033[32m
COLOR_CYAN	=	\033[36m

####################################################################
#							DEFAULT TARGET		  		   		   #
####################################################################

all:		$(NAMES) $(NAMEC)

####################################################################
#							CLIENT AND SERVER TARGET  			   #
####################################################################

$(NAMEC):	$(OBJ_CLIENT_FILE)
			@make -C libft
			@echo "$(COLOR_GREEN)Compiling Client...$(COLOR_RESET)"
			$(CC) $(FLAGS) $(OBJ_CLIENT_FILE) $(INCLUDE) libft/$(LIBFT) -o $(NAMEC)

$(NAMES):	$(OBJ_SERVER_FILE)
			@make -C libft
			@echo "$(COLOR_GREEN)Compiling Server...$(COLOR_RESET)"
			$(CC) $(FLAGS) $(OBJ_SERVER_FILE) $(INCLUDE) libft/$(LIBFT) -o $(NAMES)

####################################################################
#							OBJECT FILE RULE	  				   #
####################################################################

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@$(MKDIR) $(DIR_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

####################################################################
#							CLEANING RULES						   #
####################################################################	
	
clean:
	@echo "$(COLOR_CYAN)deleting folder .obj in Minitlalk$(COLOR_RESET)"
	$(RM) $(DIR_OBJS)
	
fclean:	clean
	@echo "$(COLOR_CYAN)deleting folder .obj and .a in libft$(COLOR_RESET)"
	@make fclean -C libft
	@echo "$(COLOR_CYAN)Deleting programs$(COLOR_RESET)"
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	
re: fclean all

.PHONY: all clean fclean re