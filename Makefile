CFLAGS  = -g -MMD -MP -Wall -Wextra -Werror
DFLAGS = -fsanitize=address -fsanitize=undefined -fsanitize=bounds
LDFLAGS =
LIBS    = lib/libft/libft.a
INCLUDE = -I./include -I./lib/libft/include
NAME    = cub3D
SRCDIR  = src
SRCS    = src/main.c
OBJDIR  = obj
OBJS    = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
DEPENDS = $(OBJS:.o=.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(INCLUDE) $(CFLAGS) $(if $(DEBUG),$(DFLAGS),) $(LDFLAGS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $(if $(DEBUG),$(DFLAGS),) $(INCLUDE) -o $@ -c $<

$(LIBS):
	$(MAKE) -C ./lib/libft

.PHONY: clean
clean:
	make -C ./lib/libft clean
	$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean: clean
	make -C ./lib/libft fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug:
	make DEBUG=1

cfile:
	find . -name "*.c" -not -path "./lib/*" | sed 's/\.\///g' | tr '\n' ' '

-include $(DEPENDS)

