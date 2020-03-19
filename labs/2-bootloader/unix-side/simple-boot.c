/* 
 * engler, cs140e: simple unix-side bootloader implementation.  
 * see the lab README.md for the protocol definition.
 */

/*********************************************************************************
 * The following starter code we give you: shouldn't have to modify.
 */
#include <unistd.h>
#include "libunix.h"

#include "unix-boot.h"

// check that the expected value <exp> is equal the the value we <got>.
// on mismatch, drains the tty and echos (to help debugging) and then 
// dies.
static void ck_eq32(int fd, const char *msg, unsigned exp, unsigned got) {
	if(exp == got)
        return;

    // i think there can be garbage in the initial /tty.
    output("%s: expected %x, got %x\n", msg, exp, got);

    // after error: just echo the pi output so we can kind of see what is going
    // on.   <TRACE_FD> is used later.
    unsigned char b;
    while(fd != TRACE_FD && read(fd, &b, 1) == 1) 
        fputc(b, stderr);
    panic("pi-boot failed\n");
}

// hack to handle unsolicited <PRINT_STRING>: 
//  1. call <get_op> for the first uint32 in a message.  
//  2. the code checks if it received a <PRINT_STRING> and emits if so;
//  3. otherwise returns the 32-bit value.
//
// error:
//  - only call IFF the word could be an opcode (see <simple-boot.h>).
//  - do not call it on data since it could falsely match a data value as a 
//    <PRINT_STRING>.
uint32_t get_op(int fd) {
    uint32_t op = get_uint32(fd);
    if(op != PRINT_STRING)
        return op;

    unsigned nbytes = get_uint32(fd);
    demand(nbytes < 512, pi sent a suspiciously long string);
    output("pi sent print: <");
    for(int i = 0; i < nbytes; i++)
        output("%c", get_uint8(fd));
    output(">\n");

    // get the next op
    return get_op(fd);
}

/*********************************************************************************
 * Put your modifications below.
 */

// Unix-side bootloader implementation.
//
// Implement steps
//    1,2,3,4.
//
//  0 and 5 are implemented as demonstration.
//
// Note: if timeout in <set_tty_to_8n1> is too small you can fail here.
//
void simple_boot(int fd, const uint8_t *buf, unsigned n) { 
    // if n is not a multiple of 4, use roundup() in libunix.h
    n = pi_roundup(n,4);
    demand(n % 4 == 0, boot code size must be a multiple of 4!);

    // all implementations should have the same HASH message: same bytes,
    // same crc32: cross-check this.
    output("HASH: simple_boot: sending %d bytes, crc32=%x\n", n, crc32(buf,n));

    // we drain the initial pipe: can have garbage.  the code is a bit odd b/c 
    // if we have a single garbage byte, then reading 32-bits will
    // will not match <GET_PROG_INFO> (obviously) and if we keep reading 
    // 32 bits then we will never sync up with the input stream, our hack
    // is to read a byte (to try to sync up) and then go back to reading 32-bit
    // ops.
    output("waiting for a start\n");
    uint32_t op;
    while((op = get_op(fd)) != GET_PROG_INFO) {
        output("expected initial GET_PROG_INFO, got <%x>: discarding.\n", op);
        // have to remove one byte since if not aligned, stays not aligned
        get_uint8(fd);
    } 
    // 1. reply to the GET_PROG_INFO
    unimplemented();

    // 2. drain any extra GET_PROG_INFOS
    unimplemented();

    // 3. check that we received a GET_CODE
    unimplemented();

    // 4. handle it: send a PUT_CODE massage.
    unimplemented();

    // 5. Wait for success
    ck_eq32(fd, "BOOT_SUCCESS mismatch", BOOT_SUCCESS, get_op(fd));
    output("bootloader: Done.\n");
}
