Main rule:
                        DO NOT MODIFY THE MAKEFILE!
                        DO NOT MODIFY THE MAKEFILE!
                        DO NOT MODIFY THE MAKEFILE!
                        DO NOT MODIFY THE MAKEFILE!
                        DO NOT MODIFY THE MAKEFILE!
                        DO NOT MODIFY THE MAKEFILE!

The subdirectories hold `.c` and `.o` files we give you:
  - `cs140e-objs`: these are `.o` files we provide.  You're going to write your own
     and remove these pretty quickly.  If you want to swap between your implementation
     and ours, modify `put-your-src-here.mk` (described below).

  - `libc`: `.c` implementation of standard library functions (often ripped off from
    `uClibc`).

  - `objs`: this is where all the .o's get put during make.  you can ignore it.

  - all other source code is at the top level prefixed with a `cs140e-`
    in the file
    name.  Last year people got lost looking for stuff, so we just put
    it all at the top.  You can write your own implementations of these
    but mostly they are are not super interesting.

You have two options:

 1. `libpi/your-src/`: new code which has no implementation from us.
    The `Makefile` automatically grabs all files in this directory
    and compiles them.  This is nice b/c you don't have to do anything.
    It's bad if you put `.c` files in there that you don't want compiled.
    We will never add or modify anything in this directory so you will
    never have conflicts.

 2. If you want to swap between our implementation and yours: put your `.c` at the
    the top level `libpi/`, add your `.o` to `put-your-src-here.mk` and remove ours.
    The `Makefile` will then compile and grab them.

Do not add files to `libc/`  --- files we add later may conflict with yours.
