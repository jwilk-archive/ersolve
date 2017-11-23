all: ersolve

ersolve: ersolve.c
	$(CC) ersolve.c -o ersolve

clean:
	rm -f ersolve

.PHONY: all clean

# vim:ts=4 sts=4 sw=4 noet
