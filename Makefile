NAME = app

CC = c++
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

HEAD = includes/main.hpp includes/Account.hpp
SRCS = srcs/main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all : $(NAME)

%.o : %.cpp Makefile $(HEAD)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re
