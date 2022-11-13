# COLORS
GREEN			:= \033[32m
NC				:= \033[m

# FLAGS
CC				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
MLXFLAGS		:= -framework OpenGL -framework AppKit
FLAGS			:= $(CFLAGS) 

RM 				:= rm -f

# SRC
MAIN			= main.c 

SRCS 			= 

# LIBS
LIBS_PATH		:= libs
LIBFT			:= bin/libft.a
LIBFT_PATH		:= libft
MLX				:= libmlx.a
MLX_PATH		:= mlx
LIBS 			:= $(LIBS_PATH)/$(LIBFT_PATH)/$(LIBFT) $(LIBS_PATH)/$(MLX_PATH)/$(MLX)

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin

#INCLUDES
INC_PATH		:= src/mandatory/inc
INCLUDES 		:= $(LIBS_PATH)/$(LIBFT_PATH) $(LIBS_PATH)/$(MLX_PATH) $(INC_PATH)
INC 			= $(addprefix -I , $(INCLUDES))

# OBJECTS
OBJS_MAIN		= $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))
OBJS_SRC		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS			= $(OBJS_MAIN) $(OBJS_SRC)


# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 			:= cub3D

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)

vpath %.c src src/assets src/mandatory src/mandatory/errors src/mandatory/helpers src/mandatory/inputs src/mandatory/maps

.SECONDEXPANSION:

all: make_libs $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) -c $(INC)  $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

make_libs:
	@make -s -C $(LIBS_PATH)/libft
	@make -s -C $(LIBS_PATH)/mlx
	@echo "$(GREEN)mlx compiled!$(NC)"

$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN) $(READ_FLAGS)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: all
	@./$(BIN)

leaks: $(BIN)
	leaks -atExit -- ./$(BIN)

leaks_test: all
	@echo "$(GREEN)Executing tests...$(NC)"
	@make leaks -e -C tests/ OBJS_SRC="$(OBJS_SRC)"

test: all
	@echo "$(GREEN)Executing tests...$(NC)"
	@make run -e -C tests/ OBJS_SRC="$(OBJS_SRC)"

check_ft:
	@nm -u ./$(BIN)

norm:
	@norminette src/$(SRC) inc/* | sh tests/norminette.sh

norm2:
	@norminette src/$(SRC) inc/*

clean:
	@make fclean -C $(LIBS_PATH)/libft
	@make clean -C $(LIBS_PATH)/mlx
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)

.PHONY: all clean fclean re leaks run test check_ft norm
