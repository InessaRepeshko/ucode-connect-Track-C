INCD = inc
OBJD = obj
SRCD = src
LIBD = libmx
LIB = $(LIBD)/libmx.a
EXE = pathfinder
SRCS := $(wildcard $(SRCD)/*.c)
OBJS := $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCS))
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

.PHONY: all install clean uninstall reinstall

all: install

install: $(LIB) $(EXE)

$(LIB):
	make -C $(LIBD)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCD) $^ $(LIB) -o $@

$(OBJS): $(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	$(CC) $(CFLAGS) -I$(INCD) -I$(LIBD)/$(INCD) -c $< -o $@

$(OBJD):
	mkdir -p $(OBJD)

uninstall: clean
	make -C $(LIBD) uninstall
	rm -f $(EXE)

clean:
	make -C $(LIBD) clean
	rm -rf $(OBJD)

reinstall: uninstall all

