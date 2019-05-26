CC=gcc -Wall -g

all: clean test

test:
	$(CC) main.c ../../link_list/link_list.c -I../../link_list -o test_link_list
	
clean:
	rm -rf test_link_list