NAME = so_long

SRC = ./mandatory/so_long.c ./mandatory/get_next_line.c ./mandatory/get_next_line_help.c \
		./mandatory/ft_split.c ./mandatory/ft_render_map.c ./mandatory/ft_init_pars_mape.c \
		./mandatory/ft_init_pars_mape_help.c ./mandatory/ft_init_mlx.c ./mandatory/ft_error_msg.c \
		./mandatory/pars_of_map.c


OBJC = $(SRC:.c=.o)

INC = -I ./mandatory -I ./minilibx-linux

CFLAGS = -Wall -Wextra -Werror
CC = cc

MLX_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


all: ${NAME}

${NAME} : ${OBJC}
	$(CC) $(CFLAGS) $(OBJC)  $(MLX_FLAGS) -o $(NAME)

%.o: %.c 
	$(CC)  $(CFLAGS) $(INC) -c $<  -o $@

clean:
	rm -rf  $(OBJC)

fclean: clean 
	rm -rf $(NAME)

re :  fclean all
