#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

extern "C" {
    typedef uint16_t word;
    typedef uint8_t byte ;
    typedef bool boolean ;

    void* malloc(size_t size);
    void free(void *ptr);
}

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;

uint32_t millis( void );
uint32_t micros( void );
void delay(uint32_t msec);
void delayMicroseconds(uint32_t us);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);

long random();
long random(long);
long random(long, long);
void randomSeed(unsigned long);

inline boolean isWhitespace(int c)
{
    return (isblank (c) == 0 ? false : true);
}

#define PROGMEM
#define F(x) x
#define pgm_read_byte_near(x) *(x)
#define memcpy_P(dst, src, n) memcpy(dst, src, n)
#define memcmp_P(p1, p2, n) memcmp(p1, p2, n)
#define strcmp_P(s1, s2) strcmp(s1, s2)
#define strlen_P(str) strlen(str)
#define pgm_read_byte(addr) *(addr);

class __FlashStringHelper;


#include "Print.h"
#include "Stream.h"

#endif // Arduino_h
