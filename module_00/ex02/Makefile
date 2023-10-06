# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:56:47 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/06 22:05:18 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Account

CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I$(INC_D)
RM			=	rm -rf

OBJS_D		=	./objects
SRCS_D		=	./sources
INC_D		=	./includes

FILES		=	Account\
				tests

SRCS		=	$(addprefix $(SRCS_D)/, $(addsuffix .cpp, $(FILES)))
OBJS		=	$(addprefix $(OBJS_D)/, $(addsuffix .o, $(FILES)))


all:			$(NAME)

$(OBJS_D)/%.o:	$(SRCS_D)/%.cpp
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
		
clean:
		$(RM) $(OBJS_D)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

#  Lorenzo Fiorini
