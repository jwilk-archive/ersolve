VERSION = 0.3.1
DISTFILES = Makefile README ersolve.c

all: ersolve

ersolve: ersolve.c
	$(CC) ersolve.c -o ersolve

clean:
	$(RM) ersolve

.PHONY: all clean
