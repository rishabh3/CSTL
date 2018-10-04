CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/stack.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/stacktest.o $(ODIR)/stack.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/stack.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/stack.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/stacktest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
