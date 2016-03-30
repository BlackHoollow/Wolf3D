# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromptea <mgras@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 18:34:51 by nromptea          #+#    #+#              #
#    Updated: 2016/03/30 17:49:01 by nromptea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = core.c utility.c parse2.c wolf.c key.c raycasting.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC_PATH = ./src/
OBJ_PATH = ./obj/

LIB_PATH = ./libft/
INC_PATH = ./include/ $(LIB_PATH)

SRC      = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ      = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC      = $(addprefix -I, $(INC_PATH))
LIB      = $(addprefix -L, $(LIB_PATH))

NAME     = wolf3d
CC       = gcc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lft

all: libft $(NAME)

.PHONY: libft clean fclean re $(NAME) gcp

libft :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LDFLAGS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@$(RM) -v $(OBJ)
	@$(RM) -rv $(OBJ_PATH)

fclean : clean
	@$(RM) -v $(NAME)

gcp : fclean
	git add -A
	git commit -m "make git"
	git push origin master

re: fclean all
