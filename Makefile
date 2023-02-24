# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:37:38 by novsiann          #+#    #+#              #
#    Updated: 2023/02/23 19:17:44 by nikitos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
BONUS_MAIN = checker.c

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/src
PUSH_MAIN = src/main.c

SRCS =  src/init_stack.c src/check_error.c src/stack_manip.c src/sort_s.c src/stack_swap.c \
		src/stck_rev_rotate.c src/stack_manip2.c src/big_sort.c src/lis.c	\
		src/stck_rotate.c src/utils.c src/bubble_sort.c src/trns_bfr_mdn.c src/stack_push.c src/small_rev_sort.c \
		src/transf_utils.c src/math_op.c\


OBJS = ${SRCS:.c=.o}
OBJS_PUSH_MAIN = $(PUSH_MAIN:.c=.o)
OBJS_BONUS_MAIN = $(BONUS_MAIN:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

all:	$(NAME)

$(NAME):	$(OBJS_PUSH_MAIN) $(OBJS)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(OBJS_PUSH_MAIN) $(OBJS) -L. -lft -lftprintf -o $(NAME)

clean:
		@make -C $(LIBFT) clean
		@make -C $(PRINTF) clean
		$(RM) $(OBJS) $(OBJS_PUSH_MAIN) $(OBJS_BONUS_MAIN)
		$(RM) libft.a libftprintf.a

bonus:	$(BONUS)

$(BONUS):	$(OBJS_BONUS_MAIN) $(OBJS)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(OBJS_BONUS_MAIN) $(OBJS) -L. -lft -lftprintf -o $(BONUS)

fclean: clean
		${RM} ${NAME} $(BONUS)

re:		fclean all

.PHONY:		all clean fclean re