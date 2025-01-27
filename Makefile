NAME = fract-ol

CC = cc 

CFLAGS = -Wall -Wextra -Werror -lX11 -lXext -g3

INC = -Iincludes

SRCFOLDER = src/

OBJFOLDER = objs/

SRC_LIST = main.c \
	init.c \

SRC = $(addprefix $(SRCFOLDER), $(SRC_LIST))

OBJS = $(patsubst $(SRCFOLDER), $(OBJFOLDER)%.o, $(SRC))

LIBS = libft/libft.a \
	minilibx-linux/libmlx.a

all : git mlx libft $(NAME)

git :
	@git submodule update --init --recursive --remote

mlx : 
	@$(MAKE) -s -C minilibx-linux

libft:
	@$(MAKE) -s -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBS) -o $@
	@echo 'fract-ol created'

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c Makefile includes/* $(LIBS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) clean -s -C libft
	@$(MAKE) clean -s -C minilibx-linux
	@rm -rf $(OBJFOLDER)
	@echo 'clean completed'

fclean: clean
	@rm -f $(NAME) $(LIBS)
	@echo 'fclean completed'

re: fclean all

.PHONY: all clean fclean re git libft mlx 
