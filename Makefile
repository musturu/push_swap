# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = libft

# Libraries
LIBSFLAG = -L$(LIBFTDIR) -lft

# Source files
SRCS =  srcs/push_swap.c srcs/validate.c srcs/init.c srcs/operations.c \
srcs/operations2.c srcs/operations3.c srcs/cost.c srcs/list_utils.c srcs/rotate_to_target.c \
srcs/solver.c srcs/memory_manager.c srcs/tiny_solver.c

OBJS =  objs/push_swap.o objs/validate.o objs/init.o objs/operations.o \
objs/operations2.o objs/operations3.o objs/solver.o objs/cost.o objs/list_utils.o \
objs/rotate_to_target.o objs/memory_manager.o objs/tiny_solver.o


# Executable name
NAME = push_swap

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror $(LIBSFLAG) -c $< -o $@


$(NAME): $(OBJS)
	@ make -C $(LIBFTDIR)
	$(CC) -Wall -Wextra -Werror $(OBJS) $(LIBSFLAG) -o $(NAME)

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

git:
	make fclean
	make -C $(LIBFTDIR) fclean
	git add .
	git commit -m "auto-commit"
	git push

.PHONY: all clean fclean re
