
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = lem-in
SRC_NAME = main.c\
	ft_bfs_queue.c\
	ft_init_lemin.c\
	ft_create_link.c\
	ft_create_room.c\
	ft_create_path.c\
	ft_print.c\
	ft_bfs.c\
	ft_prepare_links.c\
	ft_del_inforks.c\
	ft_del_outforks.c\
	ft_create_ant.c\
	ft_manipulate_ants.c
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
