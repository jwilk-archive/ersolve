VERSION = 0.3
DISTFILES = Makefile README ersolve.c

all:		ersolve

ersolve:	ersolve.c
	gcc -O2 -s ersolve.c -o ersolve

clean:
	rm -f ersolve

distclean:
	rm -f ersolve-$(VERSION).tar.*
        
dist:		distclean
	fakeroot tar cf ersolve-$(VERSION).tar $(DISTFILES)
	bzip2 -9k ersolve-$(VERSION).tar
	gzip -9 ersolve-$(VERSION).tar