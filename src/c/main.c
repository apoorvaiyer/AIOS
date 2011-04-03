#include "system.h"

unsigned char *memcpy(void *dest, const void *src, int count)
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;

    /* I used this just in case there's paging issues later on. Don't want too much thrashing :) */
    while (count --)
        *(d ++) = *(s ++);
    return dest;
}

unsigned char *memset(void *dest, unsigned char val, int count)
{
    unsigned char *d = (unsigned char *)dest;

    /* Same reason as memcpy */
    while (count--)
        *(d ++) = val;
    return dest;
}

unsigned short *memsetw(void *dest, unsigned short val, int count)
{
    /* Remember to keep local variables unsigned short */
    unsigned short *d = (unsigned short*)dest;

    /* Same reason as memcpy */
    while(count--)
        *(d++) = val;
    return dest;
}

int strlen(const char *str)
{
    int count = 0;

    /* Same reason as memcpy */
    while (*(str ++))
        count++;
    return count;
}

/* Inline assembly to get 1-byte of data from a port */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* Inline assembly to get 1-byte of data from a port */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be the 'idle' loop */
void main()
{
    /* You would add commands after here */

    /* ...and leave this loop in. There is an endless loop in
    *  'start.asm' also, if you accidentally delete this next line */
    for (;;);
}
