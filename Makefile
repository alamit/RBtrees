# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamit <alamit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 21:26:30 by alamit            #+#    #+#              #
#    Updated: 2018/10/31 08:55:23 by alamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libtree
TEST_NAME = tree
API_H = include/tree.h

CC = gcc
CFLAGS = -flto -Wall -Wextra -Werror
INCLUDE = -Iinclude -Iinclude/pvt

SRC_DIR = src
PVT_DIR = src/pvt

SRC = tree_life.c tree_insert.c tree_delete.c tree_utils.c tree_reduce.c \
		tree_print.c tree_contains.c tree_apply.c
PVT = node_family.c node_getters.c node_helpers.c node_rotations.c
TEST = main.c
OUT = $(SRC) $(PVT)

OUT := $(OUT:%.c=%.o)
SRC := $(SRC:%.c=$(SRC_DIR)/%.c)
PVT := $(PVT:%.c=$(PVT_DIR)/%.c)
SRC += $(PVT)

RM = rm -rf

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -c $(CFLAGS) $(INCLUDE) $(SRC)
	mkdir $(NAME)
	cp API_H $(NAME)
	ar -rcs $(NAME)/$(NAME).a $(OUT)

test: $(SRC) $(TEST)
	$(CC) -g $(CFLAGS) $(INCLUDE) -o $(TEST_NAME) $(SRC) $(TEST)

clean:
	$(RM) -r $(OUT) $(TEST_NAME) $(TEST_NAME).dSYM

fclean: clean
	$(RM) -r $(NAME)

re: fclean $(NAME)
