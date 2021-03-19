# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 22:48:30 by mde-figu          #+#    #+#              #
#    Updated: 2021/03/18 23:21:21 by mde-figu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c utils/variables_for_print.c utils/get_parameters.c \
utils/print_c.c utils/print_d_u.c utils/print_p.c utils/print_percent.c utils/ft_utoa.c \
utils/print_s.c utils/print_x.c utils/print.c \
utils/print_n.c utils/print_f.c utils/print_e.c

OBJ = ft_printf.o variables_for_print.o get_parameters.o \
print_c.o print_d_u.o print_p.o print_percent.o ft_utoa.o \
print_s.o print_x.o print.o \
print_n.o print_f.o print_e.o

$(NAME): ft_printf.h $(SRC)
	@$(MAKE) bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@gcc -Wall -Wextra -Werror -c $(SRC) -I printf.h -g
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

bonus: all

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean test
