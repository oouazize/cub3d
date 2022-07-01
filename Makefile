NAME    =    cub3d

SRCS    =	cub3d.c \
			events.c \
			init.c \
			drawing/draw.c \
			drawing/draw_3d.c \
			utils/ft_strjoin.c utils/ft_substr.c \
			utils/get_next_line.c \
			utils/ft_split.c \
			utils/ft_strncmp.c \
			utils/ft_strtrim.c \
			utils/ft_atoi.c \
			check_comma.c \
			check_map.c \
			replace_map.c \
			player_error.c \

GCC        =    gcc -Wall -Wextra -Werror

FLAGS =	-lmlx -framework OpenGL -framework AppKit

RM    =    rm -f

all: $(NAME)
$(NAME):   $(SRCS)
	@$(GCC) $(SRCS) $(FLAGS) -o cub3D
	@echo "\033[1;33m ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ "
	@echo "\033[1;33m██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "\033[1;33m██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "\033[1;33m██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "\033[1;33m╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo "\033[1;33m ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ "
	@echo "\033[1;33m "
	@echo " "
	@echo "\033[1;35m▐▌ DONE ▐▌"

clean:
	@$(RM)

fclean: clean
	@$(RM) $(NAME)

re:    fclean all
