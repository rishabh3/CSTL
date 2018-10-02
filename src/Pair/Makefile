CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/pair.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/pairtest.o $(ODIR)/pair.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/pair.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/pair.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/pairtest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
