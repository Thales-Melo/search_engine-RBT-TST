#include <stdio.h>
#include <stdlib.h>

#include "../include/tst.h"
#include "../include/stop_word.h"
#include "../include/utils.h"

#define STOP_WORD_DIR "stopwords.txt"

struct StopWord {
    TST *sw; // <Key: char*, Value: SPECIAL_NULL_VALUE>
};

StopWord* stop_word_construct() {
    StopWord *sw = (StopWord*) malloc(sizeof(StopWord));
    if (sw == NULL)
        exit(printf("Error StopWord_construct: failed to allocate memory.\n"));
    sw->sw = TST_construct();
    return sw;
}

void stop_word_destruct(StopWord *sw) {
    TST_destruct(sw->sw, NULL);
    free(sw);
}

void stop_word_insert(StopWord *sw, const char *word) {
    sw->sw = TST_insert(sw->sw, word, SPECIAL_NULL_VALUE);
}

bool stop_word_contains(StopWord *sw, const char *word) {
    return TST_search(sw->sw, word) != NULL;
}

void stop_word_print(StopWord *sw) {
    TST_print_keys(sw->sw);
}

StopWord *stop_word_read(char *main_dir) {
    StopWord *stop_word = stop_word_construct();

    char sw_input_file[256];
    sprintf(sw_input_file, "%s/%s", main_dir, STOP_WORD_DIR);
    FILE *file = fopen(sw_input_file, "r");
    if (file == NULL)
        exit(printf("Error stop_word_read: Failed to open file %s\n", sw_input_file));

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0'; // Remove '\n'
        string_to_lower(line);
        stop_word_insert(stop_word, line);
    }

    free(line);
    fclose(file);
    printf("Stop words read.\n");
    //stop_word_print(stop_word);
    return stop_word;
}