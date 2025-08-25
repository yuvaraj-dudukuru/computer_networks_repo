#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024
#define BIT_PATTERN "11111" // Bit pattern to insert

void bit_stuffing(char *input, char *output) {
    int i, j = 0;
    int count = 0;
    
    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) {
                // Insert the bit pattern after five consecutive '1's
                for (int k = 0; k < strlen(BIT_PATTERN); k++) {
                    output[j++] = BIT_PATTERN[k];
                }
                count = 0; // Reset count after inserting bit pattern
            }
        } else {
            count = 0; // Reset count if a '0' is encountered
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE * 2]; // Output size can be larger due to stuffing

    printf("Enter the binary data (only 0s and 1s): ");
    scanf("%s", input);

    bit_stuffing(input, output);

    printf("Original Data: %s\n", input);
    printf("Data after Bit Stuffing: %s\n", output);

    return 0;
}