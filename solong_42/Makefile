MAKEFLAGS += --silent
NAME= so_long
CC = cc
SRCS= controls_utils.c main.c map_utils.c renderingV2_0.c rendering_utils.c so_long_utils.c validpath.c
BSRCS= controls_utils_bonus.c main_bonus.c map_utils_bonus.c renderingV2_0_bonus.c rendering_utils_bonus.c so_long_utils_bonus.c validpath_bonus.c
LIB= ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS= -lmlx -framework OpenGL -framework AppKit
RM = rm -f
OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -I . $(MLX_FLAGS) $(OBJ) $(LIB) -o $@
	make clean
	echo "so_long is created"

%.o: %.c
		$(CC) $(CFLAGS) -I. -o $@ -c $?

bonus: $(BOBJ)
	make -C libft
	$(CC) $(CFLAGS) -I . $(MLX_FLAGS) $(BOBJ) $(LIB) -o $(NAME)
	echo "so_long bonus is created"

clean:
		make clean -C libft
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		echo "so_long is deleted"

re: fclean all