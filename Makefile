
NAME = so_long 

NAME_BONUS = so_long_bonus

SRCS = $(addprefix src/, main2.c utils.c virus.c mapcpy.c ft_graphical.c readfile.c move.c checkstring.c displaypix.c)

SRCSBONUS = $(addprefix src_bonus/, main2.c utils.c virus.c mapcpy.c ft_graphical.c readfile.c move.c checkstring.c displaypix.c bonus.c)

# Colors
LIBFT = libft.a

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = gcc

RM = rm -f

MLX_DIR = mlx
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L. -lXext -L. -lX11
CFLAGS = -Wall -Wextra -Werror 

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCSBONUS:.c=.o}



$(NAME):  $(MLX) $(OBJS) ${LIBFT}
		${CC} -g3 $(OBJS) $(MLX) $(MLXFLAGS) $(CFLAGS) -o $(NAME) libft.a
		
#$(OBJS) : $(HEADER)

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all:	$(NAME) 
		@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"
$(MLX):
				$(MAKE) -C $(MLX_DIR)
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

bonus: $(NAME_BONUS)
	   @echo "$(GREEN)bonus compiled!$(DEF_COLOR)"
		


$(NAME_BONUS):$(MLX) $(OBJS_BONUS) ${LIBFT}
		${CC} ${OBJS_BONUS} $(CFLAGS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

-include $(SRCS:.c=.d)

cleanlibft:
	make -C libft/ fclean


clean:
	# $(MAKE) -C $(MLX_DIR) clean
	$(RM) ${OBJS} ${OBJS_BONUS}
	make -C libft/ clean
	echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	make -C libft/ fclean
	rm -rf libft.a
	@echo "$(CYAN) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY: all clean fclean re minilibx libft bonus
