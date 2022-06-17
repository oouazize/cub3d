NAME    =    cub3d

SRCS    =	cub3d.c ft_strjoin.c ft_substr.c ft_strlen.c ft_strdup.c ft_strstr.c get_next_line.c ft_split.c ft_strchr.c ft_strncmp.c ft_strlcpy.c ft_strcmp.c ft_strtrim.c ft_atoi.c ft_isascii.c ft_isalpha.c check_comma.c check_map.c \

GCC        =    gcc -Werror -Wextra -Wall -fsanitize=address -g

FLAGS =	-lmlx -framework OpenGL -framework AppKit

RM    =    rm -f

all: $(NAME)
$(NAME):
	@$(GCC) $(SRCS) $(FLAGS) -o cub3d

clean:
	@$(RM)

fclean: clean
	@$(RM) $(NAME)

re:    fclean all