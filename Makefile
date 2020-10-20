# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 20:05:13 by asfaihi           #+#    #+#              #
#    Updated: 2020/10/20 09:29:17 by asfaihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_printf.c hexa.c libft_functions.c libft_functions_2.c \
	 	 percent_divider.c percent_s_printers.c printers.c

FLAGS = -Wall -Wextra -Werror

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o:%.c
	gcc $(FLAGS) -c $<

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
