all: ULMVM

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

ULMVM: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

ULMVM-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f ULMVM ULMVM-debug