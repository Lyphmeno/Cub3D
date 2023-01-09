NAME		:=	cub3d

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g

MLXDIR		:=	MLX42
MLXPATH		:=	${MLXDIR}/libmlx.a
MLXFLAGS	:=	-ldl -lmlx -L${MLXDIR} -lm -lXext -lX11 -Imlx 

SRCDIR		:=	src
SRCEXT		:=	c
SRC			:=	\
				./src/cub3d.c\
				./src/libasic/ft_atoi.c\
				./src/libasic/ft_bzero.c\
				./src/libasic/ft_calloc.c\
				./src/libasic/ft_memmove.c\
				./src/libasic/ft_memset.c\
				./src/libasic/ft_new_arr.c\
				./src/libasic/ft_printab.c\
				./src/libasic/ft_split.c\
				./src/libasic/ft_split_whitespaces.c\
				./src/libasic/ft_strchr.c\
				./src/libasic/ft_strdup.c\
				./src/libasic/ft_strfjoin.c\
				./src/libasic/ft_strjoin.c\
				./src/libasic/ft_strlcat.c\
				./src/libasic/ft_strlcpy.c\
				./src/libasic/ft_strlen.c\
				./src/libasic/ft_strncmp.c\
				./src/libasic/ft_substr.c\
				./src/libasic/get_next_line.c\
				./src/libasic/get_next_line_utils.c\
				./src/mlx/draw_form.c\
				./src/mlx/handle_keys.c\
				./src/mlx/minimap.c\
				./src/mlx/mlx_base.c\
				./src/mlx/move.c\
				./src/mlx/raycasting.c\
				./src/parsing/colors.c\
				./src/parsing/init.c\
				./src/parsing/mapfile.c\
				./src/parsing/parse_colors.c\
				./src/parsing/parse_info_error.c\
				./src/parsing/parse_split_info.c\
				./src/parsing/parse_map.c\
				./src/parsing/parsing.c\
				./src/parsing/parsing_utils.c\

INCDIR		:=	inc
INCEXT		:=	h
HEADERS		:=	\
				./inc/cub3d.h\
				./inc/libasic.h\
				./inc/get_next_line.h\
				./MLX42/mlx.h\

OBJDIR		:=	objs
OBJSUBDIR	:=	$(shell find $(SRCDIR) -type d | cut -d/ -f2 | awk 'NR>1')
OBJEXT		:=	o
OBJS		:=	$(subst $(SRCDIR),$(OBJDIR),$(SRC:.$(SRCEXT)=.$(OBJEXT)))

.PHONY: all
all: minilibx $(NAME)

minilibx:
			@make -C ./MLX42/

$(NAME):	$(OBJDIR) $(OBJS) $(HEADERS) Makefile
			@echo -ne '\033c$(E_BAR)\n'
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)

$(OBJDIR):
			@mkdir -p $(OBJDIR) $(OBJSUBDIR)
			@mv -f $(OBJSUBDIR) $(OBJDIR)
			@$(eval $(call update_bar))

$(OBJDIR)/%.$(OBJEXT) : 	$(SRCDIR)/%.$(SRCEXT)
							@echo -ne '\033c$(E_BAR)\n'
							$(CC) $(CFLAGS) -c -o $@ $<  -I $(INCDIR) $(MLXFLAGS)
							@$(eval $(call update_bar))

.PHONY: re
re: fclean all

.PHONY: clean
clean:
		@$(RM) -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
		@$(RM) -rf $(NAME)

#  ---------- PROGRESS BAR ----------  #
_STOP		:=	\e[0m
_PINK		:=	\033[38;5;223m\e[1m
_ORANGE		:=	\033[38;5;209m\e[1m
VAL			:=	66
_CREAM		:=	\033[38;5;${VAL}m\e[1m
INDEX		:=	1
BUILD_SIZE	:=	$(shell find $(SRCDIR) -type f -name "*.c" | wc -l)
PRC			:=	$(shell echo "$(INDEX) / $(BUILD_SIZE) * 100" | bc -l)
progress	:=	$(shell echo "$(INDEX) / ($(BUILD_SIZE) / 20)" | bc -l)

define update_bar =
    E_BAR		:=	$(_PINK)-->$(_ORANGE)[$(_STOP)$(_CREAM)$(shell python3 -c 'print("█" * int($(progress)))')$(shell python3 -c 'print(" " * (20 - int($(progress))))')$(_ORANGE)]$(_PINK)<--$(_ORANGE)[$(_CREAM)$(shell echo $(PRC) / 1 | bc)%$(_ORANGE)]$(_STOP)
	INDEX		:=	$(shell echo $(INDEX) + 1 | bc -l)
    progress	:=	$(shell echo "$(INDEX) / ($(BUILD_SIZE) / 20)" | bc -l)
	PRC			:=	$(shell echo "$(INDEX) / $(BUILD_SIZE) * 100" | bc -l)
	VAL			:=	$(shell echo $(VAL) + 1 | bc -l)
	_CREAM		:=	\033[38;5;${VAL}m\e[1m
endef
#  ---------- PROGRESS BAR ----------  #
