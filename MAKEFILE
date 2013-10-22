CC=gcc
CFLAGS=-Wall

all: compile

compile: urlencode.c
	$(CC) $(CFLAGS) urlencode.c -o urlencode

install:
	chmod +x urlencode
	mv urlencode /usr/local/bin
