CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/queue.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/queuetest.o $(ODIR)/queue.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/queue.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/queue.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/queuetest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
