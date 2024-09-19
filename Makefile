CFLAGS = -Wall -Wextra -Werror -pedantic -g

all:
	gcc $(CFLAGS) -o trab3 src/client/main.c src/libs/src/*.c
clean:
	rm -f trab3
debug:
	gcc $(CFLAGS) -DDEBUG_MODE -o trab3 src/client/main.c src/libs/src/*.c
run:
	./trab3 exemplo < exemplo/searches.txt > output_exemplo.txt
val:
	valgrind --track-origins=yes --leak-check=full -s ./trab3 exemplo < exemplo/searches.txt > output_exemplo.txt