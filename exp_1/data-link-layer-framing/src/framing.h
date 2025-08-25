#ifndef FRAMING_H
#define FRAMING_H

// Function declarations for character framing
void characterFraming(const char *data, char *framedData);

// Function declarations for character stuffing
void characterStuffing(const char *data, char *stuffedData);

// Function declarations for bit stuffing
void bitStuffing(const char *data, char *stuffedData);

// Constants for special characters used in framing and stuffing
#define START_FRAME 'S'
#define END_FRAME 'E'
#define ESCAPE_CHAR 'X'

#endif // FRAMING_H