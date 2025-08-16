#include <stdio.h>
#include <stdint.h> // Required for fixed-width integer types like uint32_t
#include <string.h> // Required for strlen()

/**
 * @brief Computes the CRC value for a given set of data.
 *
 * @param data Pointer to the data buffer.
 * @param len Length of the data buffer in bytes.
 * @param poly The generator polynomial (without the implicit leading 1).
 * @param width The width of the CRC in bits (e.g., 12, 16).
 * @return The computed CRC value.
 */
uint32_t compute_crc(const uint8_t *data, size_t len, uint32_t poly, int width) {
    // The top_bit is used to check the MSB of the CRC register.
    // It's 1 followed by (width - 1) zeros.
    uint32_t top_bit = 1 << (width - 1);
    
    // The crc register, initialized to 0.
    uint32_t crc = 0;

    // --- Main CRC Calculation Loop ---
    for (size_t i = 0; i < len; i++) {
        // XOR the next data byte into the top byte of the CRC register.
        // We shift it left to align it with the most significant bits.
        crc ^= (uint32_t)data[i] << (width - 8);

        // Process each of the 8 bits in the current byte.
        for (int j = 0; j < 8; j++) {
            // Check if the MSB of the CRC register is 1.
            if (crc & top_bit) {
                // If it is, shift left by 1 and XOR with the polynomial.
                crc = (crc << 1) ^ poly;
            } else {
                // If it's 0, just shift left by 1.
                crc <<= 1;
            }
        }
    }

    // After processing all data, the CRC might be wider than `width`.
    // We create a mask to zero out the excess bits.
    // For a 16-bit CRC, the mask is 0xFFFF. For a 12-bit CRC, it's 0xFFF.
    uint32_t mask = (1UL << width) - 1;
    
    return crc & mask;
}

int main() {
    // Sample data to compute CRC for. You can change this string.
    const char *data_str = "Hello, World!";
    const uint8_t *data = (const uint8_t *)data_str;
    size_t data_len = strlen(data_str);

    printf("Computing CRC for data: \"%s\"\n", data_str);
    printf("Data length: %zu bytes\n\n", data_len);

    // --- Define CRC Parameters ---
    // CRC-12
    uint32_t poly_12 = 0x80F;
    int width_12 = 12;

    // CRC-16 (ANSI)
    uint32_t poly_16 = 0x8005;
    int width_16 = 16;
    
    // CRC-CCITT (also known as CRC-16-CCITT)
    uint32_t poly_ccitt = 0x1021;
    int width_ccitt = 16;

    // --- Compute and Print Results ---
    uint32_t crc12_result = compute_crc(data, data_len, poly_12, width_12);
    printf("CRC-12 (0x%X): \t0x%03X\n", poly_12, crc12_result);

    uint32_t crc16_result = compute_crc(data, data_len, poly_16, width_16);
    printf("CRC-16 (0x%X): \t0x%04X\n", poly_16, crc16_result);

    uint32_t crcccitt_result = compute_crc(data, data_len, poly_ccitt, width_ccitt);
    printf("CRC-CCITT (0x%X): \t0x%04X\n", poly_ccitt, crcccitt_result);

    return 0;
}