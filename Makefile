CC := gcc
CFLAGS := -Wall -Wextra -g $(shell sdl2-config --cflags)
LDFLAGS := -I include/ $(shell sdl2-config --libs)
EXEC := ulamspiral

.PHONY: all
all: mrproper $(EXEC)

$(EXEC): src/*.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

.PHONY: run
run: all
	./$(EXEC)

.PHONY: mrproper
mrproper:
	rm -f $(EXEC)
