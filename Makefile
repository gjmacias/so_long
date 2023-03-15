NAME = so_long



INCLUDERS = sources/*.h

SOURCES = sources/*.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmx -framework OpenGL -freamework Appkit



all: $(NAME)
	
$(NAME): $(OBJECTS) $(INCLUDERS)
	$(CC) $(SOURCES) $(FLAGS) $(MLX_FLAGS) -o $(NAME)
	
clean:
 	rm -f $(OBJECTS)
 
 fclean: clean
 	rm -f $(NAME)
 
 re: fclean all
 
 
 
 .PHONY all clean fclean re
