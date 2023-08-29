# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:56:50 by lfiorini          #+#    #+#              #
#    Updated: 2023/08/29 16:07:00 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJS_D		= ./objs
SRCS_D		= ./

HEADERS		= Contact.hpp\
			PhoneBook.hpp

FILES		= main\
			Contact\
			PhoneBook

SRCS		= $(addprefix $(SRCS_D)/, $(addsuffix .cpp, $(FILES)))
OBJS		= $(addprefix $(OBJS_D)/, $(addsuffix .o, $(FILES)))

all:		$(NAME)

$(OBJS_D)/%.o: $(SRCS_D)/%.cpp $(HEADERS)
			mkdir -p $(dir $@)
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJDIR) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus
