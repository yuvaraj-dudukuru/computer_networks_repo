#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Creates frames using the Character Count method.
 * @param data The raw data string to be framed.
 */
void characterCountFraming(const char* data) {
    printf("Original Data: \"%s\"\n\n", data);
    printf("--- Sending Frames (Character Count) ---\n");

    // For demonstration, we'll create frames with a maximum payload of 5 characters.
    const int MAX_FRAME_PAYLOAD = 5;
    int dataLen = strlen(data);
    int currentIndex = 0;

    printf("Transmitted Frame Stream: ");
    while (currentIndex < dataLen) {
        // Determine the size of the current frame's payload
        int payloadSize = (dataLen - currentIndex < MAX_FRAME_PAYLOAD) ? (dataLen - currentIndex) : MAX_FRAME_PAYLOAD;

        // The 'count' field in the header is the payload size + 1 (for the count byte itself)
        printf("%d", payloadSize + 1);

        // Append the payload characters
        for (int j = 0; j < payloadSize; j++) {
            printf("%c", data[currentIndex + j]);
        }
        printf(" "); // Use a space to visually separate frames in the output
        
        currentIndex += payloadSize;
    }
    printf("\n\n--- Frame Reception ---\n");
    printf("Receiver knows the frame boundary by reading the count at the start of each frame.\n");
}

int main() {
    char data[] = "ThisIsAComputerNetworksLab";
    characterCountFraming(data);
    return 0;
}