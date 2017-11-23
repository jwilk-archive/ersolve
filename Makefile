all: ersolve

ersolve: ersolve.c
	$(CC) ersolve.c -o ersolve

clean:
	$(RM) ersolve

.PHONY: all clean
