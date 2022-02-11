# *----------- OS -----------* 

UNAME		=	$(shell uname)


# *--------- SOURCES ---------* 

SRCS_DIR	= ./srcs/
SRCS_B_DIR	= ./srcs_bonus/

SRCS		=	\
				main.c \
				win_events.c \
				win_features.c \
				win_utils.c \
				fract_parsing.c \
				fract_init.c \
				fract_render.c \
				fract_color.c \
				fract_tools.c \
				\

SRCS_B	=		\
				main_bonus.c \
				win_events_bonus.c \
				win_features_bonus.c \
				win_utils_bonus.c \
				win_move_bonus.c \
				fract_parsing_bonus.c \
				fract_init_bonus.c \
				fract_render_bonus.c \
				fract_color_bonus.c \
				fract_tools_bonus.c \
				fractal_bonus.c \
				fractal_2_bonus.c \
				\

# SRCS_LINUX	=	\

# SRCS_MAC	=	\


# *-------- GENERALS --------* 

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g -Iincludes
RM		=	rm -rf

NAME	= 	Blow_Your_Mind


# *--------- LIBFT ---------* 

LIBFT_PATH	= ./libs/libft/
LIBFT_FLAGS	= -L$(LIBFT_PATH) -lft

LIBFT_MAKE	=	@$(MAKE) -C $(LIBFT_PATH)

# *---------- MLX ----------* 

ifeq ($(UNAME), Linux)
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o) $(SRCS_LINUX:.c=.o))
OBJS_B		=	$(addprefix $(SRCS_B_DIR), $(SRCS_B:.c=.o) $(SRCS_LINUX:.c=.o))
MLX_FLAGS	=	-Llibs/mlx_linux -lmlx -lX11 -lXext -Imlx_linux -lm
MLX_PATH	=	./libs/mlx_linux/
else
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o) $(SRCS_MAC:.c=.o))
OBJS_B		=	$(addprefix $(SRCS_B_DIR), $(SRCS_B:.c=.o) $(SRCS_LINUX:.c=.o))
MLX_FLAGS	=	-Lmlx_mac -lmlx_linux -framework OpenGL -framework AppKit
MLX_PATH	=	./libs/mlx_mac/
endif

MLX_MAKE	=	@$(MAKE) -C $(MLX_PATH)


# *-------- COMPILE --------* 

%.o : %.c
			@$(CC) $(CFLAGS) -o $@ -c $< -Iinclude

ifeq ($(UNAME), Linux)
$(NAME):	$(OBJS) mlx libft
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME) $(MLX_FLAGS)
			@echo "$(NAME) created"
else
$(NAME):	$(OBJS) mlx
			@$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created"
endif

ifeq ($(UNAME), Linux)
$(NAME)_bonus :	$(OBJS_B) mlx libft
			@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT_FLAGS) -o $(NAME)_bonus $(MLX_FLAGS)
			@echo "$(NAME)_bonus created"
else
$(NAME)_bonus:	$(OBJS_B) mlx
			@$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS_B) -o $(NAME)_bonus
			@echo "$(NAME)_bonus created"
endif

# *======== RULES ========* 

all	:		${NAME}

bonus:		${NAME}_bonus

mlx :
			@$(MLX_MAKE)

libft :
			@$(LIBFT_MAKE)

clean:
			@$(MAKE) -C $(MLX_PATH) clean
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(OBJS) $(OBJS_B)
			@echo ".o deleted"

fclean:		clean
			@$(MAKE) -C $(MLX_PATH) clean
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(NAME) $(NAME)_bonus
			@echo "$(NAME) and $(NAME)_bonus deleted"

re:			fclean all

.PHONY:		all clean flcean re mlx bonus