#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4

// Simulate random loss: returns true if frame is lost
bool is_frame_lost() {
    // 20% chance of loss
    return (rand() % 100) < 20;
}

int main() {
    int send_base = 0;
    int next_seq_num = 0;
    int acked[TOTAL_FRAMES] = {0};

    srand((unsigned int)time(NULL));

    printf("Sliding Window Protocol with Go-Back-N ARQ Simulation\n");
    printf("Total Frames: %d, Window Size: %d\n\n", TOTAL_FRAMES, WINDOW_SIZE);

    while (send_base < TOTAL_FRAMES) {
        // Send frames in window
        for (int i = 0; i < WINDOW_SIZE && (send_base + i) < TOTAL_FRAMES; i++) {
            int frame = send_base + i;
            if (!acked[frame]) {
                printf("Sender: Sending frame %d\n", frame);
            }
        }

        // Simulate receiver and ACKs
        for (int i = 0; i < WINDOW_SIZE && (send_base + i) < TOTAL_FRAMES; i++) {
            int frame = send_base + i;
            if (!acked[frame]) {
                if (is_frame_lost()) {
                    printf("Receiver: Frame %d lost! Go-Back-N triggered.\n", frame);
                    break; // Go-Back-N: resend from this frame
                } else {
                    printf("Receiver: Frame %d received. Sending ACK.\n", frame);
                    acked[frame] = 1;
                }
            }
        }

        // Slide window
        while (send_base < TOTAL_FRAMES && acked[send_base]) {
            send_base++;
        }
        printf("Window slides to %d\n\n", send_base);
    }

    printf("All frames sent and acknowledged successfully.\n");
    return 0;
}