
#define _GNU_SOURCE
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define FILENAME "input.txt"

struct file_info {
    int word_count;
    int char_count;
    int line_count;
};


struct file_info *count_words(struct file_info *info, char *buf)
{
    if (info == NULL) {
	info = calloc(1, sizeof(struct file_info));
    }



    bool is_word = false;


    info->char_count += strlen(buf);

    for (size_t i = 0; i < strlen(buf); i++) {
	if (isspace(buf[i]) != 0) {
	    if (is_word) {
		is_word = false;
		info->word_count++;
	    }
	} else {
	    is_word = true;
	}
    }
    info->line_count++;
    return info;
}

int main(int argc, char *argv[])
{

    FILE *in = fopen(FILENAME, "r");
    char *line = NULL;
    int read;
    size_t len;
    struct file_info *info = NULL;

    if (in == NULL) {
	fprintf(stderr, "failed to open file %s %s\n", FILENAME, strerror(errno));
	exit(0);
    }

    while ((read = getline(&line, &len, in)) != -1) {
	info = count_words(info, line);
    }

    printf("%6d %6d %6d %s\n", info->line_count, info->word_count, info->char_count, FILENAME);

    free(info);
    free(line);

}
