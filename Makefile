# -*- MakeFile -*-

NAME_SERVER=server
NAME_CLIENT=client
FLAGS=-Werror -Wextra -Wall
SRC_SERVER=src/server.c src/exit.c
SRC_CLIENT=src/client.c
INCLUDES=libft/libft.a

all: 
# $(NAME_SERVER) $(NAME_CLIENT)

# $(NAME_SERVER):
	@make -C libft/ all
	gcc $(SRC_SERVER) $(FLAGS) $(INCLUDES) -o $(NAME_SERVER)
	gcc $(SRC_CLIENT) $(FLAGS) $(INCLUDES) -o $(NAME_CLIENT)

# $(NAME_CLIENT):
# 	# @make -C libft/ all

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make -C libft/ fclean

re: fclean all