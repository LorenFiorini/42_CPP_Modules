# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 12:56:50 by lfiorini          #+#    #+#              #
#    Updated: 2023/10/06 19:47:15 by lfiorini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PhoneBook
	
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I$(INC_D)
RM			=	rm -rf

OBJS_D		=	./objects
SRCS_D		=	./sources
INC_D		=	./includes

INCS		=	$(INC_D)/Contact.hpp\
				$(INC_D)/PhoneBook.hpp

FILES		=	main\
				Contact\
				PhoneBook

SRCS		=	$(addprefix $(SRCS_D)/, $(addsuffix .cpp, $(FILES)))
OBJS		=	$(addprefix $(OBJS_D)/, $(addsuffix .o, $(FILES)))

all:			$(NAME)

$(OBJS_D)/%.o:	$(SRCS_D)/%.cpp $(INCS)
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME):		$(OBJS) $(INCS)
				$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJDIR) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re bonus

#  Lorenzo Fiorini 
