#include <stdio.h>

int main()
{
    int bucket_size, n, out_rate, i, total = 0, pkt_size;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &out_rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    int packets[n];
    printf("Enter packet sizes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &packets[i]);
    }

    printf("\nTime\tPacket\tBucket\tSent\tDropped\n");
    for (i = 0; i < n; i++)
    {
        pkt_size = packets[i];
        printf("%d\t%d\t", i + 1, pkt_size);

        if (pkt_size + total > bucket_size)
        {
            printf("%d\t%d\t%d\n", total, out_rate, pkt_size + total - bucket_size);
            total = bucket_size; // Bucket is full
        }
        else
        {
            total += pkt_size;
            printf("%d\t", total);
            if (total < out_rate)
            {
                printf("%d\t0\n", total);
                total = 0;
            }
            else
            {
                printf("%d\t0\n", out_rate);
                total -= out_rate;
            }
        }
    }

    // Drain remaining packets in bucket
    while (total > 0)
    {
        printf("%d\t0\t%d\t", ++i, total);
        if (total < out_rate)
        {
            printf("%d\t0\n", total);
            total = 0;
        }
        else
        {
            printf("%d\t0\n", out_rate);
            total -= out_rate;
        }
    }

    return 0;
}