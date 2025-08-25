#include <stdio.h>
#include "framing.h"

int main() {
    // Sample data to be framed
    const char *data = "Hello, World!";
    
    // Character framing
    char *framed_data = character_frame(data);
    printf("Framed Data: %s\n", framed_data);
    
    // Character stuffing
    char *stuffed_data = character_stuff(data);
    printf("Stuffed Data: %s\n", stuffed_data);
    
    // Bit stuffing
    char *bit_stuffed_data = bit_stuff(data);
    printf("Bit Stuffed Data: %s\n", bit_stuffed_data);
    
    // Free allocated memory if necessary
    free(framed_data);
    free(stuffed_data);
    free(bit_stuffed_data);
    
    return 0;
}