NAME = so_long
NAME_BON = so_long_Bonus

SRC = ./mandatory/so_long.c ./mandatory/get_next_line.c ./mandatory/get_next_line_help.c \
		./mandatory/ft_split.c ./mandatory/ft_render_map.c ./mandatory/ft_init_and_pars_mape.c \
		./mandatory/ft_init_and_pars_mape_help.c ./mandatory/ft_init_mlx.c ./mandatory/ft_error_msg.c \
		./mandatory/pars_of_map.c ./mandatory/ft_handel_keypress.c ./mandatory/ft_free.c \
		./mandatory/ft_print_all.c ./mandatory/pars_of_map_help.c 

OBJC = $(SRC:.c=.o)

SRC_BON = ./Bonus/so_long_bonus.c ./Bonus/get_next_line.c ./Bonus/get_next_line_help_bonus.c \
		./Bonus/ft_split.c ./Bonus/ft_render_map_bonus.c ./Bonus/ft_init_and_pars_map_bonus.c \
		./Bonus/ft_init_and_pars_map_help_bonus.c ./Bonus/ft_init_mlx_bonus.c ./Bonus/ft_error_msg_bonus.c \
		./Bonus/pars_of_map_bonus.c ./Bonus/ft_handel_keypress_bonus.c ./Bonus/ft_free_bonus.c \
		./Bonus/ft_print_all_bonus.c ./Bonus/ft_enemy_handel.c ./Bonus/ft_render_map_help_bonus.c \

OBJC_BON = $(SRC_BON:.c=.o)

INC = -I ./mandatory -I ./minilibx-linux
INC_BON = -I ./Bonus -I ./minilibx-linux
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
CC = cc

MLX_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd


all: ${NAME}

Bonus: $(NAME_BON)

${NAME} : ${OBJC}
	$(CC) $(CFLAGS) $(OBJC)  $(MLX_FLAGS) -o $(NAME)

%.o: %.c 
	$(CC)  $(CFLAGS) $(INC) -c $<  -o $@


${NAME_BON} : ${OBJC_BON}
	$(CC) $(CFLAGS) $(OBJC_BON)  $(MLX_FLAGS) -o $(NAME_BON)

clean:
	rm -rf  $(OBJC) $(OBJC_BON)

fclean: clean 
	rm -rf $(NAME) $(NAME_BON)

re :  fclean all 
