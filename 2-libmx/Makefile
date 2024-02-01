INCD = inc
SRCD = src
OBJD = obj
LIBMX = libmx.a
SRCS := $(wildcard $(SRCD)/*.c)
OBJS := $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCS))
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

.PHONY: all install clean uninstall reinstall

all: install

install: $(LIBMX)

$(LIBMX): $(OBJD) $(OBJS)
	ar rsc $(LIBMX) $(OBJS)

$(OBJD):
	mkdir $(OBJD)

$(OBJD)/%.o:$(SRCD)/%.c
	$(CC) $(CFLAGS) -I $(INCD) -c $< -o $@

uninstall: clean
	rm -f $(LIBMX)

clean:
	rm -rf $(OBJD)

reinstall: uninstall all

