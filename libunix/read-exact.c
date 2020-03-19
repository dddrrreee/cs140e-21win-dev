#include <assert.h>
#include <unistd.h>
#include "libunix.h"

int read_exact(int fd, void *data, unsigned n) {
    assert(n);
    int got;

    if((got = read(fd, data, n)) < 0)
        sys_die(read, read_exact failed);
    if(got != n)
        panic("expected a read of %d bytes, got %d\n", n, got);
    return n;
}
