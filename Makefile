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
SRCS =  srcs/push_swap.c srcs/validate.c srcs/init.c srcs/operations.c srcs/operations2.c srcs/operations3.c
OBJS =  objs/push_swap.o objs/validate.o objs/init.o objs/operations.o objs/operations2.o objs/operations3.o


# Executable name
NAME = push_swap

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror $(LIBSFLAG) -c $< -o $@


$(NAME): $(OBJS)
	@ make -C $(LIBFTDIR)
	@ make bonus -C $(LIBFTDIR)
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
