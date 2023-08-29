# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:41:03 by lfiorini          #+#    #+#              #
#    Updated: 2023/08/29 14:24:40 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
	
CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -rf

SRCS	= megaphone.cpp

all:	$(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
		$(RM) $(NAME)

fclean:	clean

re:		fclean all

.PHONY:	all clean fclean re
