BINARY      = so_long
CODEDIRS    = . libft ./ft_printf/src ./get_next_line
INCDIRS     = . ./libft/ ./ft_printf/include ./get_next_line
LIBDIR      = ./minilibx
LIBS        = -L$(LIBDIR) -lmlx -framework AppKit -framework OpenGL

CC          = gcc

DEPFLAGS    = -MP -MD
CFLAGS      = -Wall -Wextra $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS) -O0 -g

CFILES      = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS     = $(patsubst %.c,%.o,$(CFILES))
DEPFILES    = $(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS) $(LIBDIR)/libmlx.a
	@$(CC) -o $@ $^ $(LIBS)

$(LIBDIR)/libmlx.a:
	make -C $(LIBDIR)

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)
	@make -C $(LIBDIR) clean
	$(info Binary, .o files, and .d files are cleaned.)

-include $(DEPFILES)

.PHONY: all clean
