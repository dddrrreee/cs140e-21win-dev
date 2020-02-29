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

  - `cs140e-src`: these are pi-specific source files.  You can write your own, but 
    these are not super interesting.

  - `libc`: `.c` implementation of standard library functions (often ripped off from
    `uClibc`).

  - `objs`: this is where all the .o's get put during make.  you can ignore it.

You have two options:

 1. `libpi/my-src/`: new code which has no implementation from us.
    The `Makefile` automatically grabs all files in this directory
    and compiles them.  This is nice b/c you don't have to do anything.
    It's bad if you put `.c` files in there that you don't want compiled.
    We will never add or modify anything in this directory so you will
    never have conflicts.

 2. If you want to swap between our implementation and yours: put your `.c` at the
    the top level `libpi/`, add your `.o` to `put-your-src-here.mk` and remove ours.
    The `Makefile` will then compile and grab them.

Do not add files to `cs140e-src/`  or `libc/`  --- files we add later
may conflict with yours.
