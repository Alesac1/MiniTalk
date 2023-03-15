# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:09:32 by asacchin          #+#    #+#              #
#    Updated: 2023/03/15 15:53:24 by asacchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
SRC_S = server.c
OBJ_S = $(SRC_S.o=.c)

NAME_C = client
SRC_C = client.c
OBJ_C = $(SRC_C.o=.c)

CC = gcc -Wall -Wextra -Werror

LIBFT = libft
FT_PRINTF = ft_printf
LIBRARY = ft_printf/libftprintf.a libft/libft.a

all :
		make -C $(FT_PRINTF)
		make -C $(LIBFT)
		$(CC) $(SRC_S) $(LIBRARY) -o $(NAME_S)
		$(CC) $(SRC_C) $(LIBRARY) -o $(NAME_C)

server :
		make -C $(FT_PRINTF)
		make -C $(LIBFT)
		$(CC) $(SRC_S) $(LIBRARY) -o $(NAME_S)

client :
		make -C $(FT_PRINTF)
		make -C $(LIBFT)
		$(CC) $(SRC_C) $(LIBRARY) -o $(NAME_C)

clean :
		make clean -C $(FT_PRINTF)
		make clean -C $(LIBFT)
		rm -f $(OBJ_S)
		rm -f $(OBJ_C)
		
fclean : clean
		make clean -C $(FT_PRINTF)
		make clean -C $(LIBFT)
		rm -f $(NAME_S)
		rm -f $(NAME_C)

re : fclean clean all

.PHONY: clean fclean re all