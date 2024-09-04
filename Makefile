CFLAGS = -Wextra -Werror

all:
	gcc $(CFLAGS) -o trab3 src/client/main.c src/libs/src/*.c
clean:
	rm -f trab3
debug:
	gcc $(CFLAGS) -DDEBUG_MODE -o trab3 src/client/main.c src/libs/src/*.c
valgrind:
	valgrind --track-origins=yes --leak-check=full ./trab3