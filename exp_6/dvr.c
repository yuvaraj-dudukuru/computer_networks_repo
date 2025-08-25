#include <stdio.h>
#define N 4
#define INF 999

struct Node {
    int dist[N];
    int from[N];
} rt[N];

int main() {
    int cost[N][N] = {
        {0,   1,   3, INF},
        {1,   0,   1,   4},
        {3,   1,   0,   2},
        {INF, 4,   2,   0}
    };

    // Initialize routing tables
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rt[i].dist[j] = cost[i][j];
            rt[i].from[j] = j;
        }
    }

    int updated;
    do {
        updated = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (rt[i].dist[j] > cost[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = cost[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Print routing tables
    for (int i = 0; i < N; i++) {
        printf("Routing table for Node %d:\n", i);
        printf("Dest\tNextHop\tDist\n");
        for (int j = 0; j < N; j++) {
            printf("%d\t%d\t%d\n", j, rt[i].from[j], rt[i].dist[j]);
        }
        printf("\n");
    }
    return 0;
}