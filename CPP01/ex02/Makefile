SRCS =	main.cpp		\

HEADERS =

OBJS_DIR = ./obj/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

NAME = zombie

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
	@echo "${GREEN}ZOMBIE COMPILED${NC}"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}ZOMBIE OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}ZOMBIE DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re