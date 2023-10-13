# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 22:39:01 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/13 21:55:22 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BraiiiiiiinnnzzzZ

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

SRCS_D	=	./sources
OBJS_D	=	./objects
INC_D	=	./include

FILES	=	main \
			newZombie \
			randomChump \
			Zombie

SRCS	=	$(addprefix $(SRCS_D)/, $(addsuffix .cpp, $(FILES)))
OBJS	=	$(addprefix $(OBJS_D)/, $(addsuffix .o, $(FILES)))

all:		$(NAME)

$(OBJS_D)/%.o:	$(SRCS_D)/%.cpp
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) -I$(INC_D) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS_D)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
