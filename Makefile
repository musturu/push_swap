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

BSRC = bsrc/checker.c bsrc/get_next_line_utils.c bsrc/get_next_line.c

BUTISRC = srcs/validate.c srcs/init.c srcs/operations.c \
srcs/operations2.c srcs/operations3.c srcs/list_utils.c \
srcs/memory_manager.c

BOJS = objs/checker.o objs/get_next_line.o objs/get_next_line_utils.o


# Executable name
NAME = push_swap

all: $(NAME) | bonus

$(OBJS): $(SRCS) | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror $(LIBSFLAG) -c $< -o $@
 

$(BOJS): $(BSRC)
	$(CC) -Wall -Wextra -Werror $(LIBSFLAG) -c $< -o $@


bonus :
	@ make -C $(LIBFTDIR)
	$(CC) -Wall -Wextra -Werror $(BSRC) $(BUTISRC) $(LIBSFLAG) -o checker


$(NAME):
	@ make -C $(LIBFTDIR)
	$(CC) -Wall -Wextra -Werror $(SRCS) $(LIBSFLAG) -o $(NAME)
		

$(OBJDIR):
	mkdir -p $@


clean:
	rm -rf $(OBJDIR)


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
