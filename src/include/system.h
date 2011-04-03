#ifndef __SYSTEM_H
#define __SYSTEM_H

/* MAIN.C */
extern unsigned char *memcpy(void *dest, const void *src, int count);
extern unsigned char *memset(void *dest, unsigned char val, int count);
extern unsigned short *memsetw(void *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

#endif
