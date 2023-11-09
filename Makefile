NAME = cub3d

SRCS = 	./src/main.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -c

LIBFT = ./inc/libft/libft.a

MINILIB = ./inc/minilibx-linux/libmlx.a

LINKS = -lreadline

#		42NORM_MUST_HAVE
.c.o:
	@cc $(CFLAGS) -I ./inc/ -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[0;32m compiling Libft...\n\033[0m"
	@make -C ./inc/Libft
	@printf "\033[0;32m compiling Cub3d...\n\033[0m"
	@cc $(CFLGS) $(OBJS) $(LINKS) $(LIBFT) $(MINILIB) -o $(NAME)


clean:
	@printf "\033[0;31m cleaning Libft...\n\033[0m"
	@make clean -C ./inc/Libft
	@printf "\033[0;31m cleaning Cub3d...\n\033[0m"
	@rm -f $(OBJS)


fclean: clean
	@printf "\033[0;31m fcleaning Libft...\n\033[0m"
	@make fclean -C ./inc/Libft
	@printf "\033[0;30m fcleaning Cub3d...\n\033[0m"
	@rm -f $(NAME)

#		EXTRA
#norm:
# 	@printf "\033[0;32m norminette ./Libft/*.c .h ...\n\033[0m"
# 	@make norm -C ./inc/Libft
# 	@printf "\033[0;32m norminette ./src/*.c ...\n\033[0m"
# 	@norminette $(SRCS)

# valgrind: all
# 	@printf "\033[0;32m exe with valgrind...\n\033[0m"
# 	@valgrind --show-leak-kinds=all --leak-check=full --suppressions=readline.supp ./minishell

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o
