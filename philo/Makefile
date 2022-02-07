# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2021/10/07 15:17:17 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of your executable
NAME	= philo

# Compiler and compiling flags
CC	= gcc
ifneq ($(SOFT),1)
CFLAGS	= -Wall -Werror -Wextra
endif

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif
ifeq ($(DEBUG),2)
CFLAGS	+= -g3 -fsanitize=thread
endif
ifeq ($(DEBUG),3)
CFLAGS	+= -g3 -fsanitize=address -fsanitize=leak
endif

# Folder name
SRCDIR	= src/
INCDIR	= includes/
OBJDIR	= bin/

# Add include folder
CFLAGS	+= -I $(INCDIR)

# Linking stage flags
LDFLAGS = -lpthread

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./src/let_philos_eat.c \
	./src/spawn_philos.c \
	./src/manage_threads.c \
	./src/init_data.c \
	./src/philo_/philo_thread.c \
	./src/philo_/philo_eat.c \
	./src/philo_/philo_think.c \
	./src/philo_/philo_sleep.c \
	./src/join_and_destroy.c \
	./src/utils/mutex_.c \
	./src/utils/print_timed_msg.c \
	./src/utils/fork_.c \
	./src/utils/str_to_uns.c \
	./src/utils/msleep.c \
	./src/utils/dat_/dat_get_state.c \
	./src/utils/dat_/dat_set_thread.c \
	./src/utils/dat_/dat_set_state.c \
	./src/utils/dat_/dat_get_fork.c \
	./src/utils/time_get_now.c \
	./src/DBG_print_data.c \
	./src/check_philo_death.c \
	./src/main.c \

HEADERS = \
	./includes/philo.h\
	./includes/debug_utils.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(NAME)

# Compiling
$(OBJDIR)%.o : %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GR)+$(RC)"

# Linking
$(NAME)	: $(SRCS)  $(OBJS)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "$(YE)&&& Linked [$(CC) $(LDFLAGS)] &&&\n--- $(NAME)$(RC)\n"

# Cleaning
clean :
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

# Special rule to force to remake everything
re : fclean all

# This runs the program
run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re
