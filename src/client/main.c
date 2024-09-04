#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(printf("Error: invalid number of arguments.\n"));

    char *input_dir = argv[1];

    return 0;
}