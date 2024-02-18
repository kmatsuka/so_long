NAME = so_long
SRCS = main.c handle_map.c input_map.c message_error.c error_map.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o so_long

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	
fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
