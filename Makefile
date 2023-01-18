SRCS			= $(wildcard ./src/*.c)
OBJS			= $(SRCS:.c=.o)

NAME			= cub3d
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MFLAGS			= -framework OpenGL -framework AppKit

LIB				= ./libft/libft.a
MINILIB 		= ./minilibx/libmlx.a
GNL				= ./gnl/get_next_line.a

INC_FT			= ./libft
INC_MX			= ./minilibx_opengl
INC_GNL			= ./gnl

all : $(MINILIB) $(LIB) $(GNL) ${NAME}

$(MINILIB):
	@echo "milibx compilation started"
	@make -C ./minilibx
	@echo "compilation success"

$(LIB):
	@make -C ./libft
	@echo "\x1b[33mlibft compilation success\x1b[0m"

$(GNL):
	@make -C ./gnl
	@echo "\x1b[33mget_next_line compilation success\x1b[0m"

$(NAME) : ${OBJS}
	@$(CC) $(OBJS) -o $(NAME) $(LIB) $(MINILIB) $(GNL) $(MFLAGS)
	@echo "\x1b[33msrc compilation success\x1b[0m"
.c.o :
	@${CC} ${CFLAGS} -c $< -o $@  -I$(INC_FT) -I$(INC_MX) -I$(INC_GNL)
clean :
	@${RM} ${OBJS}
	@echo "\x1b[32mClean success\x1b[0m"

fclean : clean
	@${RM} ${NAME}

ffclean: fclean
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make fclean -C ./gnl
	@make clean -C ./minilibx

norm :
	@norminette draw.c errors.c fdf.h main.c read_map.c utils.c utils2.c events.c handler.c keys.h

re : fclean all

.PHONY: all clean fclean re .c.o
