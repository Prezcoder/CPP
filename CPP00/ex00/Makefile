SRCS =	megaphone.cpp \

OBJS_DIR = ./obj/
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

NAME = megaphone

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
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}MEGAPHONE COMPILED${NC}"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${RED}MEGAPHONE OBJECTS DELETED${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}MEGAPHONE DELETED${NC}"

bonus: re

re: fclean all

.PHONY: all clean fclean bonus re