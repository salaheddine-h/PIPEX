

NAME = pipex

CC = cc

RM = rm -rf 

CFLAGS = -Wall -Wextra -Werror 

SRC = scrs/pipex.c scrs/pipex_utils.c libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	make all -C libft
	gcc $(CFLAGS) $(SRC) -o $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean : 
	$(RM) $(NAME)
	make clean -C libft

re : fclean all 

