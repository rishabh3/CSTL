CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/vec.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/vectest.o $(ODIR)/vec.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/vec.o: $(SDIR)/*.c $(SDIR)/*.h
			(mkdir $(OTDIR));
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/vec.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/vectest.o: $(TDIR)/*.c
			(mkdir $(OTDIR));
			$(CC) -c $(CFLAGS) $^ -o $@
