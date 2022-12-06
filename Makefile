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
				get_next_line.c get_next_line_utils.c strings.c memory.c helpers_1.c helpers_3.c aux_map.c checkers.c color.c \
				images.c \
				inputs.c \
				player_1.c player_2.c player_directions.c \
				raycast_1.c raycast_2.c \
				render_1.c render_2.c \
				textures_1.c textures_2.c \
				validators.c \
				window.c \

MAIN_B			= main_bonus.c

SRCS_B 			= cub_bonus.c cub_read_bonus.c cub_textures_bonus.c cub_map_bonus.c cub_player_bonus.c \
				errors_bonus.c \
				exit_bonus.c \
				game_bonus.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c strings_bonus.c memory_bonus.c helpers_1_bonus.c helpers_3_bonus.c aux_map_bonus.c checkers_bonus.c color_bonus.c \
				images_bonus.c \
				inputs_bonus.c \
				player_1_bonus.c player_2_bonus.c player_directions_bonus.c \
				raycast_1_bonus.c raycast_2_bonus.c \
				render_1_bonus.c render_2_bonus.c render_weapon_bonus.c \
				textures_1_bonus.c textures_2_bonus.c \
				validators_bonus.c \
				window_bonus.c \

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

INC			= $(addprefix -I , $(INCLUDES))

INCLUDES_B		:= $(LIBS_PATH)/$(LIBFT_PATH) $(LIBS_PATH)/$(MLX_PATH) \
					src/bonus/cub \
					src/bonus/errors \
					src/bonus/exit \
					src/bonus/game \
					src/bonus/helpers \
					src/bonus/images \
					src/bonus/inputs \
					src/bonus/player \
					src/bonus/raycast \
					src/bonus/render \
					src/bonus/textures \
					src/bonus/types \
					src/bonus/validators \
					src/bonus/window \

INC_B			= $(addprefix -I , $(INCLUDES_B))

# OBJECTS
OBJS_MAIN		= $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))
OBJS_SRC		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS			= $(OBJS_MAIN) $(OBJS_SRC)

OBJS_MAIN_B		= $(addprefix $(OBJS_DIR)/, $(MAIN_B:.c=.o))
OBJS_SRC_B		= $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))
OBJS_B			= $(OBJS_MAIN_B) $(OBJS_SRC_B)


# DEPENDECES
DEPS				= $(patsubst %.o, %.d, $(OBJS)) 
DEPS_B				= $(patsubst %.o, %.d, $(OBJS_B)) 
DEPFLAGS			= -MMD -MF

# PROGRAM NAME
NAME 				:= cub3D
NAME_B 			:= cub3D_bonus

# BINARY PATH
BIN = $(BIN_DIR)/$(NAME)
BIN_B = $(BIN_DIR)/$(NAME_B)

vpath %.c src src/assets src/mandatory src/mandatory/game src/mandatory/exit src/mandatory/window \
	src/mandatory/cub_info src/mandatory/helpers src/mandatory/inputs \
	src/mandatory/raycast src/mandatory/player src/mandatory/textures src/mandatory/helpers \
	src/mandatory/validators src/mandatory/cub src/mandatory/errors src/mandatory/images src/mandatory/render \
	\
	src/bonus \
	src/bonus src/bonus/game src/bonus/exit src/bonus/window \
	src/bonus/cub_info src/bonus/helpers src/bonus/inputs \
	src/bonus/raycast src/bonus/player src/bonus/textures src/bonus/helpers \
	src/bonus/validators src/bonus/cub src/bonus/errors src/bonus/images src/bonus/render

.SECONDEXPANSION:

all: $(LIBFT) $(MLX) $(BIN)

bonus: $(LIBFT) $(MLX) $(BIN_B)

$(OBJS_DIR)/%.o: %.c | $$(@D)
	@$(CC) $(FLAGS) -c $(INC) $(INC_B) $< -o $@ $(DEPFLAGS) $(patsubst %.o, %.d, $@) 


$(LIBFT): libft_force_make
	@make -C $(LIBS_PATH)/libft
	
$(MLX): mlx_force_make
	@make -s -C $(LIBS_PATH)/mlx 2> ERRORS
	@rm ERRORS


$(BIN): $(OBJS) $(BIN_DIR) $(LIBS)
	@echo "$(BLUE)$(NAME) compiling...$(NC)"
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS) $(LIBS) -o $(BIN)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

$(BIN_B): $(OBJS_B) $(BIN_DIR) $(LIBS)
	@echo "$(BLUE)$(NAME_B) compiling...$(NC)"
	@$(CC) $(FLAGS) $(MLXFLAGS) $(INC) $(OBJS_B) $(LIBS) -o $(BIN_B)
	@echo "$(GREEN)$(NAME_B) compiled!$(NC)"


run: all
	@./$(BIN) ./src/assets/maps/mandatory/map.cub

run_b: bonus
	@./$(BIN_B) ./src/assets/maps/bonus/map.cub

leaks: $(BIN)
	leaks -atExit -- ./$(BIN) ./src/assets/maps/mandatory/map.cub

test: all
	@echo "$(BLUE)Executing tests...$(NC)"
	@make run -e -C tests/ OBJS_SRC="$(OBJS_SRC)"

check_ft:
	@nm -u ./$(BIN)

norm:
	@norminette src/* libs/libft

clean:
	@make fclean -C $(LIBS_PATH)/libft
	@make clean -C $(LIBS_PATH)/mlx
	@$(RM) $(OBJS) $(DEPS)
	@$(RM) $(OBJS_B) $(DEPS_B)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"
	@echo "$(GREEN)$(NAME_B) cleaned!$(NC)"

fclean:		clean
	@$(RM) $(BIN)
	@$(RM) $(BIN_B)

re:	fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

-include $(DEPS)
-include $(DEPS_B)

.PHONY: all clean fclean re leaks run test check_ft norm norm2 libft_force_make mlx_force_make bonus
