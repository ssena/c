
#define _GNU_SOURCE
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define FILENAME "input.txt"




int count_words(char *buf)
{

    int word_count = 0;
    bool is_word = false;

    for (size_t i = 0; i < strlen(buf); i++) {
	if (isspace(buf[i]) != 0) {
	    if (is_word) {
		is_word = false;
		word_count++;
	    }
	} else {
	    is_word = true;
	}
    }
    return word_count;
}

int main(int argc, char *argv[])
{

    FILE *in = fopen(FILENAME, "r");
    char *line = NULL;
    int read;
    size_t len;
    int word_count = 0;

    if (in == NULL) {
	fprintf(stderr, "failed to open file %s %s\n", FILENAME, strerror(errno));
	exit(0);
    }

    while ((read = getline(&line, &len, in)) != -1) {
	word_count += count_words(line);
    }

    printf("Word count = %d\n", word_count);
}
