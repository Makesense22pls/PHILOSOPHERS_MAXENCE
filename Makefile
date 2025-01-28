# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2025/01/28 23:22:45 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -f
SRC = exec/main.c parsing/parsing.c exec/set_table.c exec/monitor.c exec/init_philo_mutex.c exec/routine.c exec/time_check.c
OBJ = $(SRC:.c=.o)

#HEADERS

all : $(NAME)


%.o: %.c
	gcc $(CFLAGS) -I. -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -o $@


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all