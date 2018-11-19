CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/deque.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/dequetest.o $(ODIR)/deque.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/deque.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/deque.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/dequetest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
