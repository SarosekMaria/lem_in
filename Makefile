# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 20:15:19 by sassassi          #+#    #+#              #
#    Updated: 2020/10/07 22:08:40 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = lem-in
VS_NAME = vs
SRC_NAME = ft_add_command.c\
	ft_add_links.c\
	ft_add_out.c\
	ft_add_room.c\
	ft_build_group.c\
	ft_cleaner_ant.c\
	ft_create_ant.c\
	ft_create_gpaths.c\
	ft_create_group.c\
	ft_create_link.c\
	ft_create_nodes.c\
	ft_create_path.c\
	ft_create_room.c\
	ft_create_tree.c\
	ft_del_dead_ends.c\
	ft_init_lemin.c\
	ft_manipulate_ant.c\
	ft_navigation.c\
	ft_path_utils.c\
	ft_print_path.c\
	ft_print.c\
	ft_solution_utils.c\
	ft_solution.c\
	ft_val_overflow.c\
	ft_val.c\
	main.c
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC_DIR = ./includes/
INC = -I $(INC_DIR) -I $(SDL_HEADERS)
LIB_DIR = ./libft/
SRC_DIR = src/
LIBRARIES = -lftprintf -L$(LIB_DIR) -L$(SDL_LIBRARY) -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_gfx
SDL_LIBRARY = $(HOME)/.brew/lib
SDL_HEADERS = $(HOME)/.brew/include
LIBFT = $(LIB_DIR)libftprintf.a
VS_SOURCES_LIST = vs.c\
				vs2.c\
				vs3.c\
				vs4.c\
				vs5.c\
				vs6.c\
				vs7.c
VS_SOURCES = $(addprefix $(SRC_DIR), $(VS_SOURCES_LIST))
VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
VS_OBJECTS = $(addprefix $(OBJ_DIR), $(VS_OBJECTS_LIST))

all: $(NAME) $(VS_NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./$(LIB_DIR) -lftprintf -g

$(VS_NAME): $(LIBFT) $(OBJ_DIR) $(VS_OBJECTS) $(OBJ)
	@$(CC) $(FLAGS) -o $(VS_NAME) $(LIBRARIES) $(INC) $(VS_OBJECTS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VS_NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
