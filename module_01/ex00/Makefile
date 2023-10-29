# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 22:39:01 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/29 06:19:08 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombies

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

SRC_D	=	./sources
OBJ_D	=	./objects
INC_D	=	./include

FILES	=	main \
			newZombie \
			randomChump \
			Zombie

SRCS	=	$(addprefix $(SRC_D)/, $(addsuffix .cpp, $(FILES)))
OBJS	=	$(addprefix $(OBJ_D)/, $(addsuffix .o, $(FILES)))

all:		$(NAME)

$(OBJ_D)/%.o:	$(SRC_D)/%.cpp
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) -I$(INC_D) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJ_D)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
