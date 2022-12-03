# COLORS
GREEN			:= \033[32m
BLUE			:= \033[34m
NC				:= \033[m

# FLAGS
CC				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
MLXFLAGS		:= -framework OpenGL -framework AppKit
FLAGS			:= $(CFLAGS) 

RM 				:= rm -f

# SRC
MAIN			= main.c

SRCS 			= cub.c cub_read.c cub_textures.c cub_map.c cub_player.c \
				errors.c \
				exit.c \
				game.c \
				get_next_line.c strings.c memory.c helpers_1.c helpers_3.c aux_map.c checkers.c color.c \
				images.c \
				inputs.c \
				player_1.c player_2.c \
				raycast_1.c raycast_2.c \
				render.c \
				textures_1.c textures_2.c \
				validators.c \
				window.c \

# LIBS
LIBS_PATH		:= libs
LIBFT_PATH		:= libft
LIBFT			:= $(LIBS_PATH)/$(LIBFT_PATH)/bin/libft.a
MLX_PATH		:= mlx
MLX				:= $(LIBS_PATH)/$(MLX_PATH)/libmlx.a
LIBS 			:= $(LIBFT) $(MLX)

# FOLDERS
OBJS_DIR		:= obj
BIN_DIR			:= bin

#INCLUDES
INCLUDES 		:= $(LIBS_PATH)/$(LIBFT_PATH) $(LIBS_PATH)/$(MLX_PATH) \
					src/mandatory/cub \
					src/mandatory/errors \
					src/mandatory/exit \
					src/mandatory/game \
					src/mandatory/helpers \
					src/mandatory/images \
					src/mandatory/inputs \
					src/mandatory/player \
					src/mandatory/raycast \
					src/mandatory/render \
					src/mandatory/textures \
					src/mandatory/types \
					src/mandatory/validators \
					src/mandatory/window \

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

vpath %.c src src/assets src/mandatory src/mandatory/game src/mandatory/exit src/mandatory/window \
	src/mandatory/cub_info src/mandatory/helpers src/mandatory/inputs \
	src/mandatory/raycast src/mandatory/player src/mandatory/textures src/mandatory/helpers \
	src/mandatory/validators src/mandatory/cub src/mandatory/errors src/mandatory/images src/mandatory/render
# vpath %.c src src/assets src/mandatory src/mandatory/cub_info src/mandatory/helpers src/mandatory/inputs src/mandatory/maps

.SECONDEXPANSION:

all: $(LIBFT) $(MLX) $(BIN)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) -c $(INC)  $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 

$(LIBFT): libft_force_make
	@make -C $(LIBS_PATH)/libft
	
$(MLX): mlx_force_make
	@make -s -C $(LIBS_PATH)/mlx 2> ERRORS
	@rm ERRORS


$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@echo "$(BLUE)$(NAME) compiling...$(NC)"
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

run: all
	@./$(BIN) ./src/assets/maps/map.cub

leaks: $(BIN)
	leaks -atExit -- ./$(BIN)

test: all
	@echo "$(BLUE)Executing tests...$(NC)"
	@make run -e -C tests/ OBJS_SRC="$(OBJS_SRC)"

check_ft:
	@nm -u ./$(BIN)

norm:
	@norminette src/$(SRC) $(INCLUDES)  | sh tests/norminette.sh

norm2:
	@norminette src/$(SRC) $(INCLUDES) 

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

.PHONY: all clean fclean re leaks run test check_ft norm norm2 libft_force_make mlx_force_make
