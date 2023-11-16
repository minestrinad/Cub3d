NAME = cub3d

SRCS = 	./src/main.c \
		./src/parse_infos.c \
		./src/parse_map.c \
		./src/utils.c \
		./src/deal_window.c \
		./src/ft_close.c \
		./src/mlx_utils.c \
		./src/draw.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -c

MLX_FLAGS = -L./mlx_linux -lmlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a


#		42NORM_MUST_HAVE
.c.o:
	@printf "\033[0;33m compiling $<\n\033[0m"
	@cc $(CFLAGS) -I./libft -I./inc -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[0;32m compiling Libft...\n\033[0m"
	@make -C ./libft
	@printf "\033[0;32m compiling Cub3d...\n\033[0m"
	@cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)


clean:
	@printf "\033[0;31m cleaning Libft...\n\033[0m"
	@make clean -C ./libft
	@printf "\033[0;31m cleaning Cub3d...\n\033[0m"
	@rm -f $(OBJS)


fclean: clean
	@printf "\033[0;31m fcleaning Libft...\n\033[0m"
	@make fclean -C ./libft
	@printf "\033[0;30m fcleaning Cub3d...\n\033[0m"
	@rm -f $(NAME)

#		EXTRA
#norm:
# 	@printf "\033[0;32m norminette ./Libft/*.c .h ...\n\033[0m"
# 	@make norm -C ./libft
# 	@printf "\033[0;32m norminette ./src/*.c ...\n\033[0m"
# 	@norminette $(SRCS)

valgrind: all
	@printf "\033[0;32m exe with valgrind...\n\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) default.cub

fsaniter: fclean fclean $(OBJS)
	@make -C ./libft
	@printf "\033[0;32m exe with fsaniter...\n\033[0m"
	@cc -g -fsanitize=address $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o
