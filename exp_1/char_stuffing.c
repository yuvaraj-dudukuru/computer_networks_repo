#include <stdio.h>
#include <string.h>

// Define special characters
#define FLAG '$'
#define ESC  '#'

/**
 * @brief Implements character stuffing on the sender side.
 * @param data The raw data string.
 * @param stuffedData Buffer to store the stuffed data.
 */
void sender_charStuffing(const char* data, char* stuffedData) {
    int dataLen = strlen(data);
    int stuffedIndex = 0;

    // 1. Add starting flag
    stuffedData[stuffedIndex++] = FLAG;

    // 2. Scan data and stuff characters
    for (int i = 0; i < dataLen; i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            // If a FLAG or ESC is found in data, stuff an ESC before it
            stuffedData[stuffedIndex++] = ESC;
        }
        stuffedData[stuffedIndex++] = data[i];
    }

    // 3. Add ending flag
    stuffedData[stuffedIndex++] = FLAG;
    stuffedData[stuffedIndex] = '\0'; // Null-terminate the string
}

/**
 * @brief Implements character de-stuffing on the receiver side.
 * @param stuffedData The received frame with stuffed characters.
 * @param destuffedData Buffer to store the original data.
 */
void receiver_charDestuffing(const char* stuffedData, char* destuffedData) {
    // Length - 1 to ignore the final flag. Start at 1 to ignore the first flag.
    int stuffedLen = strlen(stuffedData) - 1;
    int destuffedIndex = 0;

    for (int i = 1; i < stuffedLen; i++) {
        if (stuffedData[i] == ESC) {
            // If an ESC is found, skip it and take the next character literally
            i++;
        }
        destuffedData[destuffedIndex++] = stuffedData[i];
    }
    destuffedData[destuffedIndex] = '\0'; // Null-terminate the string
}


int main() {
    // Sample data containing the FLAG and ESC characters
    char data[] = "Data$with#special$chars";
    char stuffed[200];
    char destuffed[200];

    printf("Original Data: %s\n\n", data);
    
    // --- Sender Side ---
    printf("--- Sender Side ---\n");
    sender_charStuffing(data, stuffed);
    printf("Transmitted Frame (Stuffed): %s\n\n", stuffed);
    
    // --- Receiver Side ---
    printf("--- Receiver Side ---\n");
    printf("Received Frame: %s\n", stuffed);
    receiver_charDestuffing(stuffed, destuffed);
    printf("Data after De-stuffing: %s\n", destuffed);

    return 0;
}