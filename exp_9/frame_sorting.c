#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 100

// Structure to represent a frame
typedef struct {
    int seq_no;
    char data[50];
} Frame;

// Comparison function for qsort
int compare_frames(const void *a, const void *b) {
    Frame *fa = (Frame *)a;
    Frame *fb = (Frame *)b;
    return fa->seq_no - fb->seq_no;
}

int main() {
    int n;
    Frame buffer[MAX_FRAMES];

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter sequence number and data for each frame (out of order):\n");
    for (int i = 0; i < n; i++) {
        printf("Frame %d sequence number: ", i + 1);
        scanf("%d", &buffer[i].seq_no);
        printf("Frame %d data: ", i + 1);
        scanf("%s", buffer[i].data);
    }

    // Sort frames by sequence number
    qsort(buffer, n, sizeof(Frame), compare_frames);

    printf("\nFrames after sorting (in order):\n");
    for (int i = 0; i < n; i++) {
        printf("Seq No: %d, Data: %s\n", buffer[i].seq_no, buffer[i].data);
    }

    return 0;
}