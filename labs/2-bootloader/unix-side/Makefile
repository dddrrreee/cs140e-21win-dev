CC = gcc
SRC = my-install.c simple-boot.c  send-recv.c
OBJS = $(SRC:.c=.o)

# check that your path is defined.
ifndef CS140E_2021_PATH
$(error CS140E_2021_PATH is not set: this should contain the absolute path to where this directory is.  Define it in your shell's initialiation.  For example, .tcshrc for tcsh or .bashrc for bash)
endif
PATH_LIBUNIX = $(CS140E_2021_PATH)/libunix
LIBUNIX = $(PATH_LIBUNIX)/libunix.a
CFLAGS = -Wall -Werror -g  -Og -Ilibunix  -Wno-unused-function  -Wall -I$(PATH_LIBUNIX)

# uncomment:
#   - the 'run' target to automatically run the hello.bin code.
#   - the 'tags' target to run tags on the code.  this is super
#     helpful.
all : libunix my-install # run # tags 

libunix:
	make -C $(PATH_LIBUNIX)

my-install:  $(OBJS)  $(LIBUNIX)
	$(CC) $(CFLAGS) $(OBJS) -o my-install -lm $(LIBUNIX)

tags:
	ctags *.[ch]

run:
	./my-install ./hello.bin


clean :
	rm -f *.o *~ Makefile.bak my-install  tags
	make -C $(PATH_LIBUNIX) clean

.PHONY: run clean tags libunix
