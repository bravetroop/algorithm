CC=gcc -Wall -g

all: clean test

test:
	$(CC) main.c link_list.c -I./ -o test_link_list
	
clean:
	rm -rf test_link_list
