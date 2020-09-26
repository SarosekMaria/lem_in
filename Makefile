
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = lem-in
SRC_NAME = main.c\
	ft_add_command.c\
	ft_add_links.c\
	ft_add_out.c\
	ft_add_room.c\
	ft_build_group.c\
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
	ft_navigation.c\
	ft_path_utils.c\
	ft_print.c\
	ft_solution_utils.c\
	ft_solution.c\
	ft_val_overflow.c\
	ft_valid_input.c
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC_DIR = includes/
INC = -I $(INC_DIR)
LIB_DIR = libft/
SRC_DIR = src/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./$(LIB_DIR) -lftprintf -g

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
