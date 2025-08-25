#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Generic CRC computation function
uint32_t compute_crc(const uint8_t *data, size_t len, uint32_t poly, int width)
{
    uint32_t top_bit = 1 << (width - 1);
    uint32_t crc = 0;

    for (size_t i = 0; i < len; i++)
    {
        crc ^= (uint32_t)data[i] << (width - 8);
        for (int j = 0; j < 8; j++)
        {
            if (crc & top_bit)
                crc = (crc << 1) ^ poly;
            else
                crc <<= 1;
        }
    }
    uint32_t mask = (1UL << width) - 1;
    return crc & mask;
}

int main()
{
    const char *data_str = "Hello, World!";
    const uint8_t *data = (const uint8_t *)data_str;
    size_t data_len = strlen(data_str);

    // CRC-12: x^12 + x^11 + x^3 + x^2 + x + 1 (0x80F)
    uint32_t poly_12 = 0x80F;
    int width_12 = 12;

    // CRC-16: x^16 + x^15 + x^2 + 1 (0x8005)
    uint32_t poly_16 = 0x8005;
    int width_16 = 16;

    // CRC-CCITT: x^16 + x^12 + x^5 + 1 (0x1021)
    uint32_t poly_ccitt = 0x1021;
    int width_ccitt = 16;

    printf("Input: %s\n", data_str);

    uint32_t crc12 = compute_crc(data, data_len, poly_12, width_12);
    printf("CRC-12:    0x%03X\n", crc12);

    uint32_t crc16 = compute_crc(data, data_len, poly_16, width_16);
    printf("CRC-16:    0x%04X\n", crc16);

    uint32_t crcccitt = compute_crc(data, data_len, poly_ccitt, width_ccitt);
    printf("CRC-CCITT: 0x%04X\n", crcccitt);

    return 0;
}