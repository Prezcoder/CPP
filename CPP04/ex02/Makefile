
NAME = AAnimal

SRCS =	main.cpp		\
		AAnimal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		Brain.cpp		\
		WrongAnimal.cpp	\
		WrongCat.cpp	\

HEADERS = AAnimal.hpp		\
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
	@echo "${GREEN}AANIMAL COMPILED${NC}"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}AANIMAL OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}AANIMAL DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re