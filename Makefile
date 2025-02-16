NAME = so_long

SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c map_read.c lib.c map_cont.c move.c img_cont.c victory.c flood_fill.c free.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_LIB = ft_printf/libftprintf.a

MINILIB_LINUX = minilibx-linux/libmlx.a

LDFLAGS = -Lminilibx-linux -Lft_printf

LDLIBS = $(FT_PRINTF_LIB) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(OBJ) $(MINILIB_LINUX)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(FT_PRINTF_LIB):
	$(MAKE) -C ft_printf

$(MINILIB_LINUX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJ)
	$(MAKE) -C ft_printf clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean


re: fclean all

.PHONY: all clean fclean re 