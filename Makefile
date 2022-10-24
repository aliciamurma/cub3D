GREEN			:= \033[32m
NC				:= \033[m

NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = main.c check.c check_map.c close.c get_next_line.c info_cub.c read.c utils.c

INC = -I $(INC_DIR)
	  
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP             = $(addsuffix .d, $(basename $(OBJ)))

CC = gcc

CFLAGS 			= -Werror -Wall -Wextra -MMD $(INC)
PTHREADS        = -lpthread
RM_DIR          = rm -rf
MKDIR           = mkdir -p

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c Makefile
	@$(MKDIR) $(dir $@)
	$(CC) -c $(FLAGS) -Imlx -I mlx/mlx.h $< -o $@
	@echo "Compiling..."

all: $(NAME)

-include $(DEP)

$(NAME) : $(OBJ)
#	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
