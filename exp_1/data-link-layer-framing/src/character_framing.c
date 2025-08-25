#include <stdio.h>
#include <string.h>

#define START_FRAME 'S'
#define END_FRAME 'E'

void character_frame(const char *data, char *framed_data) {
    int i = 0;
    int j = 0;

    framed_data[j++] = START_FRAME; // Add start frame character

    while (data[i] != '\0') {
        framed_data[j++] = data[i++];
    }

    framed_data[j++] = END_FRAME; // Add end frame character
    framed_data[j] = '\0'; // Null-terminate the framed data
}

void print_framed_data(const char *framed_data) {
    printf("Framed Data: %s\n", framed_data);
}