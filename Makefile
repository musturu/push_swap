# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs/
OBJDIR = objs/
LIBFTDIR = libft/
BONUSDIR = bsrc/
BONUSOBJDIR = bobj/


# Libraries
LIBSFLAG = -L$(LIBFTDIR) -lft

# Source files
SRC =  push_swap.c validate.c init.c operations.c \
operations2.c operations3.c cost.c list_utils.c rotate_to_target.c \
solver.c memory_manager.c tiny_solver.c

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJDIR), $(OBJ)) 

BSRC = bsrc/checker.c bsrc/get_next_line_utils.c bsrc/get_next_line.c

BUTISRC = srcs/validate.c srcs/init.c srcs/operations.c \
srcs/operations2.c srcs/operations3.c srcs/list_utils.c \
srcs/memory_manager.c $(BSRC)

BOJS = objs/validate.o objs/init.o objs/operations2.o objs/operations3.o objs/operations.o \
	   objs/list_utils.o objs/memory_manager.o bobj/checker.o bobj/get_next_line.o \
	   bobj/get_next_line_utils.o

# Executable name
NAME = push_swap
CHECKER = checker

all: bonus $(NAME) 

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUSOBJDIR)%.o: $(BONUSDIR)%.c | $(BONUSOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(CHECKER)

$(CHECKER) : $(BOJS) $(OBJS)
	@ make -C $(LIBFTDIR)
	$(CC) -Wall -Wextra -Werror $(BOJS) $(LIBSFLAG) -o $(CHECKER)

$(NAME): $(OBJS)
	@ make -C $(LIBFTDIR)
	$(CC) -Wall -Wextra -Werror $(OBJS) $(LIBSFLAG) -o $(NAME)

$(OBJDIR):
	mkdir -p $@

$(BONUSOBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BONUSOBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f checker

re: fclean all

git:
	make fclean
	make -C $(LIBFTDIR) fclean
	git add .
	git commit -m "auto-commit"
	git push

.PHONY: all clean fclean re
