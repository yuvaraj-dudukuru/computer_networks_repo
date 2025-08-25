#include <stdio.h>
#include <string.h>

#define SPECIAL_CHAR 'X' // Define a special character for stuffing

// Function to perform character stuffing
void character_stuffing(const char *input, char *output) {
    int j = 0; // Output index
    for (int i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i]; // Copy the original character
        if (input[i] == SPECIAL_CHAR) {
            output[j++] = SPECIAL_CHAR; // Stuff the special character
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Example usage
int main() {
    const char *data = "Hello X World!"; // Input data
    char stuffed_data[100]; // Buffer for stuffed data

    character_stuffing(data, stuffed_data); // Perform character stuffing
    printf("Original Data: %s\n", data);
    printf("Stuffed Data: %s\n", stuffed_data);

    return 0;
}