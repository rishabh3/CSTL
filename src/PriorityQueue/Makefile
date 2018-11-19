CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/pqueue.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/pqueuetest.o $(ODIR)/pqueue.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/pqueue.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/pqueue.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/pqueuetest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
