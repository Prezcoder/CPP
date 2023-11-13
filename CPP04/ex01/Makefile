
NAME = Brain

SRCS =	main.cpp		\
		Animal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		Brain.cpp		\
		WrongAnimal.cpp	\
		WrongCat.cpp	\

HEADERS = Animal.hpp		\
		  Dog.hpp			\
		  Cat.hpp			\
		  Brain.hpp			\
		  WrongAnimal.hpp	\
		  WrongCat.hpp		\

OBJS_DIR = ./obj/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(OBJS_DIR)%.o:%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}BRAIN COMPILED${NC}"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}BRAIN OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}BRAIN DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re