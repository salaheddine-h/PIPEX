# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salhali <salhali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 18:30:46 by salhali           #+#    #+#              #
#    Updated: 2025/01/21 17:44:57 by salhali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror 

SRC = source/pipex.c source/pipex_utils.c libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)
	
clean : 
	make clean -C libft
	$(RM) $(NAME)

re : fclean all 
