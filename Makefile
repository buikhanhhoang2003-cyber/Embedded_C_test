CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
TARGETS = parser test_parse_args

.PHONY: all clean test

all: $(TARGETS)

parser: main.c
	$(CC) $(CFLAGS) main.c -o parser

test_parse_args: test_parse_args.c
	$(CC) $(CFLAGS) test_parse_args.c -o test_parse_args

test: test_parse_args
	./test_parse_args

clean:
	rm -f $(TARGETS)

.PHONY: all clean test
