CC = cc
CFLAGS =  -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

NAME = so_long
BNAME = so_long_bonus
EXT = .c
SRCDIR = .
HEADERS = $(wildcard ./*.h);
OBJDIR = obj
LIBFT = ./libft/libft.a
OBJ_DIR= mkdir -p obj
SRC= src/controls_utils.c src/main.c src/map_utils.c src/renderingV2_0.c src/rendering_utils.c src/so_long_utils.c src/validpath.c
BSRC= src/controls_utils_bonus.c src/main_bonus.c src/map_utils_bonus.c src/renderingV2_0_bonus.c src/rendering_utils_bonus.c src/so_long_utils_bonus.c src/validpath_bonus.c

OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
BOBJ = $(BSRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)

RM = rm -rf
DELOBJ = $(OBJ) $(BOBJ)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) $(HEADERS)
	$(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(BOBJ) $(HEADERS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBFT) -o $(BNAME) $(BOBJ)

.PHONY: clean
clean: 
	make clean -C ./libft

.PHONY: fclean
fclean: clean 
	$(RM) $(NAME) $(BNAME)

.PHONY: re
re: fclean all