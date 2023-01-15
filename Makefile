# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2023/01/15 10:25:14 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and flags

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -march=native -O2 -pipe
ARFLAGS				:= 	-rcs

# Define the directories

SRC_DIR				:=	list linked_list circular_linked_list double_linked_list
SRC_DIR				+=	dqueue dynamic_dqueue
SRC_DIR				+=	graph
SRC_DIR				+=	binary_search_tree
SRC_DIR				+=	max_heap
SRC_DIR				+=	sorting
SRC_DIR				+=	hashing

OBJ_DIR				:=	obj
INC_DIR				:=	includes

# Define the source files

SRCS				:=	$(wildcard */*.c)
OBJS				:=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Define the variables for progress bar

TOTAL_FILES			:=	$(shell find . -type f -name '*.c' | wc -l)
COMPILED_FILES		:=	0
STEP				:=	100

# Define the name

NAME				:=	magic.a

# Define the rules

all:
	@$(MAKE) -j $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "\n$(MAGENTA)[DATA_STRUCTURE] Make Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o : %.c | dir_guard
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $^ -o $@
	$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[DATA_STRUCTURE] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

dir_guard:
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SRC_DIR))

norm:
	@(norminette | grep Error) || (printf "$(GREEN)[DATA_STRUCTURE]:\tNorminette Success\n$(DEF_COLOR)")

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)[DATA_STRUCTURE]:\tobj. dep. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CYAN)[DATA_STRUCTURE]:\texec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and Rebuilt everything for data_structure!\n$(DEF_COLOR)"

.PHONY:	all clean fclean re dir_guard norm

# Colors

DEF_COLOR	=	\033[1;39m
YELLOW		=	\033[1;33m
GRAY		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
MAGENTA		=	\033[1;95m
CYAN		=	\033[1;96m
WHITE		=	\033[1;97m
