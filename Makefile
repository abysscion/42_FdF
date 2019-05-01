NAME	=	fdf

# sorces and objects
SRC		=	init.c \
			drawer.c \
			reader.c \
			validator.c \
			event_listener.c \
			freer.c \
			mat.c \
			point.c \
			config_box.c \
			pmat.c \
			main.c

OBJ		=	$(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror

# ft library
FT_LIB	= $(addprefix $(FT),libft.a)
FT		= ./lib/libft/
FT_INC	= -I ./lib/libft/
FT_LNK	= -L ./lib/libft -lft


# mlx library linux
# MLX_LIB	= $(addprefix $(MLX),mlx.a)
# MLX		= ./lib/libmlx/
# MLX_INC	= -I ./lib/libmlx/
# MLX_LNK	= -L ./lib/libmlx -lmlx -lXext -lX11 

# mlx library macOS
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX		= ./lib/libmlx_macos/
MLX_INC	= -I ./lib/libmlx_macos/
MLX_LNK	= -L ./lib/libmlx_macos/ -lmlx -framework OpenGL -framework AppKit

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
