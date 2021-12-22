NAME		= minitalk

SSRCS		= server.c \
			  mini_utils.c \

CSRCS		= client.c \
			  mini_utils.c \

FLAGS		= -Wall -Werror -Wextra

$(NAME):
		gcc $(FLAGS) $(SSRCS) -o server
		gcc $(FLAGS) $(CSRCS) -o client

all: $(NAME)

clean:
		rm -f server client

fclean:	clean
		rm -f server client

re: fclean all
