# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2023/03/01 07:12:40 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#   Define the compiler and flags                                              #
# ---------------------------------------------------------------------------- #

CC                  :=	cc
CFLAGS              :=	-Wall -Wextra -Werror -march=native -O2 -pipe
CPPFLAGS            :=	-I include
ARFLAGS             := 	-rcs

ifdef DEBUG
	CFLAGS	+= -g -fsanitize=address,leak,undefined
endif

# ---------------------------------------------------------------------------- #
#   Define the directories                                                     #
# ---------------------------------------------------------------------------- #

SRC_DIR             :=	array list clist dlist deque ddeque graph
SRC_DIR				+=	binary_search_tree max_heap sorting hashing
OBJ_DIR             :=	object

# ---------------------------------------------------------------------------- #
#   Define the source files                                                    #
# ---------------------------------------------------------------------------- #

SRCS                :=	$(wildcard */*.c)
OBJS                :=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# ---------------------------------------------------------------------------- #
#   Define the variables for progress bar                                      #
# ---------------------------------------------------------------------------- #

TOTAL_FILES         :=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES      :=	0
STEP                :=	100

# ---------------------------------------------------------------------------- #
#   Define the name                                                            #
# ---------------------------------------------------------------------------- #

NAME                :=	libds.a

# ---------------------------------------------------------------------------- #
#   Define the rules                                                           #
# ---------------------------------------------------------------------------- #

all:
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "\n$(MAGENTA)[LIBDS] Make Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o: %.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[LIBDS] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)[LIBDS] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CYAN)[LIBDS] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and Rebuilt everything for libDS!\n$(DEF_COLOR)"

dir_guard:
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SRC_DIR))

norm:
	@(norminette | grep Error) || (printf "$(GREEN)[LIBDS] Norminette Success\n$(DEF_COLOR)")

debug:
	@$(MAKE) fclean
	@$(MAKE) DEBUG=1 all
	
.PHONY:	all clean fclean re dir_guard norm debug

# ---------------------------------------------------------------------------- #
#   Define the colors                                                          #
# ---------------------------------------------------------------------------- #

DEF_COLOR           =	\033[1;39m
GRAY                =	\033[1;90m
RED                 =	\033[1;91m
GREEN               =	\033[1;92m
YELLOW              =	\033[1;93m
BLUE                =	\033[1;94m
MAGENTA             =	\033[1;95m
CYAN                =	\033[1;96m
WHITE               =	\033[1;97m
