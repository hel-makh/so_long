SRCSDIR			=	srcs

HEADER			=	mandatory/includes/so_long.h

HEADER_BONUS	=	bonus/includes/so_long.h

NAME			=	so_long

MAIN			=	mandatory/main.c

MAIN_BONUS		=	bonus/main.c

SRCS			=	mandatory/$(SRCSDIR)/ft_strcpy.c\
					mandatory/$(SRCSDIR)/ft_strnjoin.c\
					mandatory/$(SRCSDIR)/ft_free.c\
					mandatory/$(SRCSDIR)/get_next_line.c\
					mandatory/$(SRCSDIR)/ft_parse_map.c\
					mandatory/$(SRCSDIR)/ft_validate_map.c\
					mandatory/$(SRCSDIR)/ft_assets.c\
					mandatory/$(SRCSDIR)/ft_movements.c\
					mandatory/$(SRCSDIR)/ft_quit_program.c

SRCS_BONUS		=	$(SRCS)

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)\
					$(MAIN_BONUS:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				make -C minilibx_mms_20200219
				mv minilibx_mms_20200219/libmlx.dylib ./libmlx.dylib
				make bonus -C Libft
				mv Libft/libft.a ./libft.a
				$(GCC) $(CFLAGS) libft.a libmlx.dylib $(OBJS) -o $(NAME)

bonus:			$(OBJS_BONUS) $(HEADER_BONUS)
				make -C minilibx_mms_20200219
				mv minilibx_mms_20200219/libmlx.dylib ./libmlx.dylib
				make bonus -C Libft
				mv Libft/libft.a ./libft.a
				$(GCC) $(CFLAGS) libft.a libmlx.dylib $(OBJS_BONUS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make clean -C minilibx_mms_20200219
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME) libft.a libmlx.dylib

re:				fclean all

.PHONY:			all bonus clean fclean re