CC=gcc
CFLAGS=-O -Wall

all: encode decode

encode: urlencode.c
	$(CC) $(CFLAGS) urlencode.c -o urlencode

decode: urldecode.c
	$(CC) $(CFLAGS) urldecode.c -o urldecode

install:
	chmod +x urlencode
	mv urlencode /usr/local/bin
	chmod +x urldecode
	mv urldecode /usr/local/bin
