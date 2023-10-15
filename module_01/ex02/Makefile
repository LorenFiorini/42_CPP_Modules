# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 22:39:33 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/15 03:49:41 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	Zombie_ex02

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

SRC_D	=	./sources
OBJ_D	=	./objects

FILE	=	main

SRC		=	$(addprefix $(SRC_D)/, $(addsuffix .cpp, $(FILE)))
OBJ		=	$(addprefix $(OBJ_D)/, $(addsuffix .o, $(FILE)))

all:		$(NAME)

$(OBJ_D)/%.o:	$(SRC_D)/%.cpp
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ_D)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
