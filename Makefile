NAME = so_long

HEADERS =	sources/so_long.h\
			get_next_line/get_next_line.h\
			minilibx/mlx.h

INCLUDES =	minilibx/libmlx.a

SOURCES =	sources/ft_check_map.c\
			sources/ft_draw_map.c\
			sources/ft_finish.c\
			sources/ft_move_key.c\
			sources/ft_read_map.c\
			sources/ft_utils.c\
			sources/so_long.c\
			get_next_line/get_next_line_utils.c\
			get_next_line/get_next_line.c\

OBJECTS = $(SOURCES:.c=.o)
DIR_OBJ	= objects

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -framework OpenGL -framework Appkit



all	:	make_lib make_dir $(NAME)

make_lib:
		@make -C minilibx

make_dir:
		@mkdir -p $(DIR_OBJ)

$(OBJS_DIR)/%.o: sources/%.c  $(INCLUDES) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJECTS) $(HEADERS)
	@echo "Compiling so long"
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)
	@echo "Done!"

clean	:
	@echo "Removing (so_long) objects..."
	make clean -C minilibx
	rm -rf $(DIR_OBJ)
	@echo "Done!"

fclean	:	clean
	@echo "Removing execute (so_long)..."
	rm -f $(NAME)
	@echo "Done!"

re	:	fclean all

.PHONY : all clean fclean re make_dir