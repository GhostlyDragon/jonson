# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboulakr <aboulakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 17:22:36 by aboulakr          #+#    #+#              #
#    Updated: 2025/05/12 06:23:43 by aboulakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
SANITEER = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -std=c++98 $(SANITEER)
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe


%.o: %.cpp PmergeMe.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all