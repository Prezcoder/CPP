SRCS =	main.cpp		\
		Fixed.cpp		\

HEADERS = -I Fixed.hpp	\

OBJS_DIR = ./obj/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

NAME = ex02

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0;0m

all: $(NAME)

$(OBJS_DIR)%.o:%.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) -o $(NAME)
	@echo "${GREEN}EX02 COMPILED${NC}"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}EX02 OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}EX02 DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re