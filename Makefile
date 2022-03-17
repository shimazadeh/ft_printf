# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shabibol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:55:59 by shabibol          #+#    #+#              #
#    Updated: 2022/03/17 17:41:30 by shabibol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

SRCS = ft_base_function.c ft_base_function_partII.c ft_paddings.c ft_parsing.c ft_print_subs.c ft_printf.c ft_put.c 

OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

all:: $(NAME)

bonus: $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
