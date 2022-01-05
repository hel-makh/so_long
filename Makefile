
HEADER			=	mandatory/includes/so_long.h

HEADER_BONUS	=	bonus/includes/so_long.h

NAME			=	so_long

MAIN			=	mandatory/main.c

SRCS			=	mandatory/srcs/ft_strcpy.c\
					mandatory/srcs/ft_strnjoin.c\
					mandatory/srcs/ft_free.c\
					mandatory/srcs/get_next_line.c\
					mandatory/srcs/ft_parse_map.c\
					mandatory/srcs/ft_validate_map.c\
					mandatory/srcs/ft_assets.c\
					mandatory/srcs/ft_movements.c\
					mandatory/srcs/ft_quit_program.c

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

MAIN_BONUS		=	bonus/main.c

SRCS_BONUS		=	bonus/srcs/ft_arrlen.c\
					bonus/srcs/ft_strcpy.c\
					bonus/srcs/ft_strnjoin.c\
					bonus/srcs/ft_free.c\
					bonus/srcs/get_next_line.c\
					bonus/srcs/ft_create_trgb.c\
					bonus/srcs/ft_parse_map.c\
					bonus/srcs/ft_validate_map.c\
					bonus/srcs/ft_init_assets.c\
					bonus/srcs/ft_update_frames.c\
					bonus/srcs/ft_render_frames.c\
					bonus/srcs/ft_render_components.c\
					bonus/srcs/ft_player_movements.c\
					bonus/srcs/ft_enemy_movements.c\
					bonus/srcs/ft_quit_program.c

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)\
					$(MAIN_BONUS:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				make -C minilibx
				mv minilibx/libmlx.dylib ./libmlx.dylib
				make bonus -C Libft
				mv Libft/libft.a ./libft.a
				$(GCC) $(CFLAGS) libft.a libmlx.dylib $(OBJS) -o $(NAME)

bonus:			$(OBJS_BONUS) $(HEADER_BONUS)
				make -C minilibx
				mv minilibx/libmlx.dylib ./libmlx.dylib
				make bonus -C Libft
				mv Libft/libft.a ./libft.a
				$(GCC) $(CFLAGS) libft.a libmlx.dylib $(OBJS_BONUS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make clean -C minilibx
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME) libft.a libmlx.dylib

re:				fclean all

.PHONY:			all bonus clean fclean re