# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2025/02/04 00:24:57 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra -pthread -g3
RM = rm -f
SRC = exec/main.c parsing/parsing.c exec/utils.c exec/set_table.c exec/monitor.c exec/init_philo_mutex.c exec/routine.c exec/routine_utils.c exec/time_check.c
OBJ = $(SRC:.c=.o)


all : $(NAME)


%.o: %.c
	cc $(CFLAGS) -I. -c $< -o $@ 

$(NAME): $(OBJ)
	 	cc  $(CFLAGS) $(OBJ) -I. -o $@


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all