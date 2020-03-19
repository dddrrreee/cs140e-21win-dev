// engler, cs140e: prototypes for various unix-side library routines.
// 
//      DO NOT MODIFY!!!   add your prototypes to libunix-extra.h
//      DO NOT MODIFY!!!   add your prototypes to libunix-extra.h
//      DO NOT MODIFY!!!   add your prototypes to libunix-extra.h
//      DO NOT MODIFY!!!   add your prototypes to libunix-extra.h
//
#ifndef __LIB_UNIX_H__
#define __LIB_UNIX_H__
#include <stdint.h>
#include <sys/types.h>

/****************************************************************
 * we give you the following routines. 
 */

// bunch of useful macros for debugging/error checking.
#include "demand.h"

// return a strdup's string.
char *strcatf(const char *fmt, ...);

// roundup <x> to a multiple of <n>: taken from the lcc compiler.
#define pi_roundup(x,n) (((x)+((n)-1))&(~((n)-1)))

/************************************************
 * I/O routines.
 */

// write exactly <n> bytes: panics if short write.
int write_exact(int fd, const void *data, unsigned n);
// read exactly <n> bytes: panics if short read.
int read_exact(int fd, void *data, unsigned n);

void put_uint8(int fd, uint8_t b);
void put_uint32(int fd, uint32_t u);
uint8_t get_uint8(int fd);
uint32_t get_uint32(int fd);


/************************************************
 * tty routines.
 */

// opens the ttyusb <device> and returns file descriptor.
int open_tty(const char *device);

// used to set a tty to the 8n1 protocol needed by the tty-serial.
int set_tty_to_8n1(int fd, unsigned speed, double timeout);

// returns 1 if the tty is not there, 0 otherwise.
// used to detect when the user pulls the tty-serial device out.
int tty_gone(const char *ttyname);

// read and echo the characters from the usbtty until it closes 
// (pi rebooted) or we see a string indicating a clean shutdown.
void pi_echo(int fd, const char *portname);


// this is used for lab 5 and onward.
enum { TRACE_FD = 21 };

/****************************************************************
 * prototypes for routines you implement.
 */

// looks in /dev for a ttyusb device. 
// returns:
//  - device name.
// panic's if 0 or more than 1.
char *find_ttyusb(void);

// read file <name> in its entirety.
//
// returns:
//  - malloc'd pointer to all data that was in <name> padded with 
//    0s up to the next multiple of 4.  
//  - <size>: bytes of data read in.
// fatal error open/read of <name> fails.
uint8_t *read_file(unsigned *size, const char *name);

// if you make your own routines, put their prototypes in 
// <libunix-extra.h> to prevent any git conflicts.
#include "libunix-extra.h"

#endif
