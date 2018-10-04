CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/list.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/listtest.o $(ODIR)/list.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/list.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/list.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/listtest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
