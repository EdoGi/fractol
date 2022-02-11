# *----------- OS -----------* 

UNAME		=	$(shell uname)


# *--------- SOURCES ---------* 

SRCS_DIR	= ./srcs/
SRCS		=	\
				main.c \
				win_management.c \
				win_events.c \
				fract_parsing.c \
				fract_render.c \
				fract_color.c \
				fract_tools.c \
				utils.c \
				bonus_fractal.c \
				move.c \
				\
				
# SRCS_LINUX	=	\

# SRCS_MAC	=	\


# *-------- GENERALS --------* 

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g -Iincludes
CFLAGS	+=	-fsanitize=address -g3
RM		=	rm -rf

NAME	= 	Blow_Your_Mind


# *--------- LIBFT ---------* 

LIBFT_PATH	= ./includes/libft/
LIBFT_FLAGS	= -L$(LIBFT_PATH) -lft

LIBFT_MAKE	=	@$(MAKE) -C $(LIBFT_PATH)

# *---------- MLX ----------* 

ifeq ($(UNAME), Linux)
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o) $(SRCS_LINUX:.c=.o))
MLX_FLAGS	=	-Lmlx_linux -lmlx -lX11 -lXext -Imlx_linux -lm
MLX_PATH	=	./mlx_linux/
else
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:.c=.o) $(SRCS_MAC:.c=.o))
MLX_FLAGS	=	-Lmlx_mac -lmlx -framework OpenGL -framework AppKit
MLX_PATH	=	./mlx_mac/
endif

MLX_MAKE	=	@$(MAKE) -C $(MLX_PATH)


# *-------- COMPILE --------* 

%.o : %.c
			@$(CC) $(CFLAGS) -o $@ -c $< -Iinclude

ifeq ($(UNAME), Linux)
$(NAME):	$(OBJS) mlx libft
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
			@echo "$(NAME) created"
else
$(NAME):	$(OBJS) mlx
			@$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)
			@echo "$(NAME) created"
endif


# *======== RULES ========* 

all	:		${NAME}

mlx :
			@$(MLX_MAKE)

libft :
			@$(LIBFT_MAKE)

bonus:		all

clean:
			@$(MAKE) -C $(MLX_PATH) clean
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(OBJS)
			@echo ".o deleted"

fclean:		clean
			@$(MAKE) -C $(MLX_PATH) clean
			@$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(NAME)
			@echo "$(NAME) deleted"

re:			fclean all

.PHONY:		all clean flcean re mlx bonus