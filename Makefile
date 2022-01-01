SRCSDIR			=	srcs

INCDIR			=	./includes

HEADER			=	$(INCDIR)/so_long.h

# HEADER_BONUS	=	$(HEADER)\
# 					$(INCDIR)/so_long_bonus.h

NAME			=	so_long

MAIN			=	main.c

# MAIN_BONUS		=	main_bonus.c

SRCS			=	$(SRCSDIR)/ft_strcpy.c\
					$(SRCSDIR)/ft_strnjoin.c\
					$(SRCSDIR)/ft_free.c\
					$(SRCSDIR)/get_next_line.c\
					$(SRCSDIR)/ft_parse_map.c\
					$(SRCSDIR)/ft_validate_map.c\
					$(SRCSDIR)/ft_assets.c\
					$(SRCSDIR)/ft_movements.c\
					$(SRCSDIR)/ft_quit_program.c

# SRCS_BONUS		=	$(SRCS)

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

# OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)\
# 					$(MAIN_BONUS:.c=.o)

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
				$(GCC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
				make -C minilibx_mms_20200219
				make bonus -C Libft
				$(GCC) $(CFLAGS) Libft/libft.a minilibx_mms_20200219/libmlx.dylib $(OBJS) -o $(NAME)

# bonus:			$(OBJS_BONUS) $(HEADER_BONUS)
# 				$(GCC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make clean -C minilibx_mms_20200219
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft

re:				fclean all

.PHONY:			all bonus clean fclean re