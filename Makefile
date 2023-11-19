CFLAGS  = -g -MMD -MP -Wall -Wextra -Werror
DFLAGS = -fsanitize=address -fsanitize=undefined -fsanitize=bounds
LDFLAGS = -framework OpenGL -framework AppKit -L/usr/X11R6/lib -lX11 -lXext
LIBS    = lib/libft/libft.a lib/minilibx-linux/libmlx_Darwin.a
INCLUDE = -I./include -I./lib/libft/include -I./lib/minilibx-linux \
	-I./src/utils \
	-I./src/parser
NAME    = cub3D
SRCDIR  = src
SRCS    = \
	src/drawing/frame_buffer.c \
	src/drawing/init_drawing.c \
	src/drawing/draw_utils.c \
	src/utils/error_msg.c \
	src/utils/double_abs.c \
	src/game/close_window.c \
	src/game/game_loop.c \
	src/game/player_movement.c \
	src/game/hook.c \
	src/game/eye_movement.c \
	src/game/init_player.c \
	src/parser/check_map.c \
	src/parser/get_config.c \
	src/parser/utils.c \
	src/parser/set_color_data.c \
	src/parser/check_map_wall.c \
	src/parser/set_texture_data.c \
	src/parser/set_map_arrange.c \
	src/parser/set_map_data.c \
	src/parser/set_color_to_world.c \
	src/main.c \
	src/dda/perform_dda.c \
	src/dda/prepare_dda.c
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
	$(MAKE) -C ./lib/minilibx-linux

.PHONY: clean
clean:
	make -C ./lib/libft clean
	$(MAKE) -C ./lib/minilibx-linux clean
	$(RM) -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	make -C ./lib/libft fclean
	$(RM) -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: debug
debug:
	make DEBUG=1

norm:
	norminette src include lib/libft

submodule:
	git submodule init
	git submodule update

cfile:
	find . -name "*.c" -not -path "./lib/*" | sed 's/\.\///g' | awk '{print "\t"$$0" \\"}' | sed '$$s/ \\//'

-include $(DEPENDS)
