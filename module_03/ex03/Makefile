# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 11:46:52 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/30 00:40:29 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= NowItIsWeird

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRC_D	= ./source
OBJ_D	= ./objects
INC_D	= ./include

FILES	=	main \
			ClapTrap \
			DiamondTrap \
			FragTrap \
			ScavTrap

SRCS	= $(addprefix $(SRC_D)/, $(addsuffix .cpp, $(FILES)))
OBJS	= $(addprefix $(OBJ_D)/, $(addsuffix .o, $(FILES)))

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
