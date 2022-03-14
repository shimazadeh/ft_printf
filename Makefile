# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shabibol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:55:59 by shabibol          #+#    #+#              #
#    Updated: 2022/03/14 16:11:31 by shabibol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 

SRCS_BONUS = 

OBJS = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

$(OBJ_BONUS): $(SRCS_BONUS) $(SRCS)
	gcc $(FLAGS) -c $(SRCS_BONUS) $(SRCS)

all:: $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
