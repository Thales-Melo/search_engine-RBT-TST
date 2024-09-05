#include <stdio.h>
#include <stdlib.h>

#include "../libs/include/stop_word.h"

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(printf("Error: invalid number of arguments.\n"));

    StopWord *stop_word = stop_word_read(argv[1]);
    
    stop_word_destruct(stop_word);
    return 0;
}