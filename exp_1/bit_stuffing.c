#include <stdio.h>
#include <string.h>

/**
 * @brief Performs bit stuffing on a bit string.
 * @param data The original bit string.
 * @param stuffedData Buffer to store the stuffed result.
 */
void sender_bitStuffing(const char* data, char* stuffedData) {
    int dataLen = strlen(data);
    int stuffedIndex = 0;
    int consecutiveOnes = 0;

    for (int i = 0; i < dataLen; i++) {
        if (data[i] == '1') {
            consecutiveOnes++;
        } else {
            consecutiveOnes = 0;
        }
        
        stuffedData[stuffedIndex++] = data[i];

        // If five 1s are encountered, stuff a 0
        if (consecutiveOnes == 5) {
            stuffedData[stuffedIndex++] = '0';
            consecutiveOnes = 0;
        }
    }
    stuffedData[stuffedIndex] = '\0';
}

/**
 * @brief Performs bit de-stuffing on a received bit string.
 * @param stuffedData The received bit string.
 * @param destuffedData Buffer to store the original result.
 */
void receiver_bitDestuffing(const char* stuffedData, char* destuffedData) {
    int stuffedLen = strlen(stuffedData);
    int destuffedIndex = 0;
    int consecutiveOnes = 0;

    for (int i = 0; i < stuffedLen; i++) {
        if (stuffedData[i] == '1') {
            consecutiveOnes++;
        } else {
            consecutiveOnes = 0;
        }

        // If we see five 1s and the next bit is a 0, it's a stuffed bit.
        if (consecutiveOnes == 5 && (i + 1 < stuffedLen) && stuffedData[i + 1] == '0') {
            // Copy the five 1s
            destuffedData[destuffedIndex++] = stuffedData[i];
            // Skip the stuffed '0' bit in the source
            i++; 
            consecutiveOnes = 0;
        } else {
            destuffedData[destuffedIndex++] = stuffedData[i];
        }
    }
    destuffedData[destuffedIndex] = '\0';
}

int main() {
    const char* flag = "01111110";
    // Sample data with a sequence of five and six 1s
    char data[] = "11010111111010111110";
    char stuffed[200];
    char destuffed[200];

    printf("Original Data: %s\n\n", data);

    // --- Sender Side ---
    printf("--- Sender Side ---\n");
    sender_bitStuffing(data, stuffed);
    printf("Transmitted Frame: %s %s %s\n\n", flag, stuffed, flag);

    // --- Receiver Side ---
    printf("--- Receiver Side ---\n");
    printf("Received Frame Payload: %s\n", stuffed);
    receiver_bitDestuffing(stuffed, destuffed);
    printf("Data after De-stuffing: %s\n", destuffed);

    return 0;
}