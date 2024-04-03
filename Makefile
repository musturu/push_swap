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
SRCS =  \
OBJS =  \


# Executable name
NAME = push_swap

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -Wall -Wextra -Werror  $(LIBSFLAG) -c $< -o $@


$(NAME): $(OBJS)
	@ make -C $(FT_PRINTFDIR)
	@ make -C $(MLXDIR)
	@ make -C $(LIBFTDIR)
	$(CC) $(OBJS) $(LIBSFLAG) -o $(NAME)

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
