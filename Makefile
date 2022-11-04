NAME		:=	cub3d

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
MLXFLAGS	:=	-Imlx_linux

SRCDIR		:=	src
SRCEXT		:=	c
SRC			:=	./src/cub3d.c\
				./src/parsing/mapfile.c\
				./src/parsing/parsing.c\
				./src/libasic/ft_memmove.c\
				./src/libasic/ft_strlen.c\
				./src/libasic/ft_bzero.c\
				./src/libasic/ft_memset.c\
				./src/libasic/ft_strchr.c\

INCDIR		:=	inc
INCEXT		:=	h
HEADERS		:=	./inc/cub3d.h\
				./inc/libasic.h\
				./MLX42/include/MLX42/MLX42.h\

OBJDIR		:=	objs
OBJEXT		:=	o
OBJS		:=	$(subst $(SRCDIR),$(OBJDIR),$(SRC:.$(SRCEXT)=.$(OBJEXT)))

.PHONY: all
all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJS) $(HEADERS) Makefile
			@echo -ne '\033c$(E_BAR)\n'
			@mv $(SRCDIR)/*.$(OBJEXT) $(OBJDIR)
			@mv $(SRCDIR)/*/*.$(OBJEXT) $(OBJDIR)
			$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) 

$(OBJDIR):
			@mkdir $(OBJDIR)
			@$(eval $(call update_bar))

$(OBJDIR)/%.$(OBJEXT) : 	$(SRCDIR)/%.$(SRCEXT)
							@echo -ne '\033c$(E_BAR)\n'
							@$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $(<:.$(SRCEXT)=.$(OBJEXT)) -I $(INCDIR)
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
VAL			:=	76
_CREAM		:=	\033[38;5;${VAL}m\e[1m
INDEX		:=	1
BUILD_SIZE	:=	$(shell find . -type f -name "*.c" | wc -l)
PRC			:=	$(shell echo "$(INDEX) / $(BUILD_SIZE) * 100" | bc -l)
progress	:=	$(shell echo "$(INDEX) / ($(BUILD_SIZE) / 20)" | bc -l)

define update_bar =
    E_BAR		:=	$(_PINK)-->$(_ORANGE)[$(_STOP)$(_CREAM)$(shell python -c 'print("█" * int($(progress)))')$(shell python -c 'print(" " * (20 - int($(progress))))')$(_ORANGE)]$(_PINK)<--$(_ORANGE)[$(_CREAM)$(shell echo $(PRC) / 1 | bc)%$(_ORANGE)]$(_STOP)
	INDEX		:=	$(shell echo $(INDEX) + 1 | bc -l)
    progress	:=	$(shell echo "$(INDEX) / ($(BUILD_SIZE) / 20)" | bc -l)
	PRC			:=	$(shell echo "$(INDEX) / $(BUILD_SIZE) * 100" | bc -l)
	VAL			:=	$(shell echo $(VAL) + 1 | bc -l)
	_CREAM		:=	\033[38;5;${VAL}m\e[1m
endef
#  ---------- PROGRESS BAR ----------  #
