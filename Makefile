# Copyright © 2003-2017 Jakub Wilk <jwilk@jwilk.net>
# SPDX-License-Identifier: MIT

CFLAGS ?= -g -O2
CFLAGS += -Wall

all: ersolve

ersolve: ersolve.c

clean:
	rm -f ersolve

.PHONY: all clean

# vim:ts=4 sts=4 sw=4 noet
