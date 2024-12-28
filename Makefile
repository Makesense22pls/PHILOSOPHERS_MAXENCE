# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxencefournier <maxencefournier@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/12/27 19:10:15 by maxencefour      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -f
SRC = exec/main.c parsing/check_args.c exec/thread.c  exec/innit.c
OBJ = $(SRC:.c=.o)

#LIB
LIBFT_DIR = headers/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a


#HEADERS
HEADERS_LIB = $(LIBFT_DIR)

all : $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o: %.c
	gcc $(CFLAGS) -I. -I$(HEADERS_LIB) -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -I$(HEADERS_LIB) -lft -L$(LIBFT_DIR) -o $@


clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean 

re: fclean all