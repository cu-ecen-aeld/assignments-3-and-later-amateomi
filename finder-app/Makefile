NAME = writer

CC = $(CROSS_COMPILE)gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

default:
	$(CC) $(CFLAGS) -o $(NAME) writer.c

clean:
	rm -f $(NAME) *.o
