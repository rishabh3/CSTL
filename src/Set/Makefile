CC = /usr/bin/gcc
CFLAGS = -Wall -g -fpic
SDIR = src
ODIR = bin
LODIR = ../../bin
OTDIR = tbin
TDIR = test
RM = /bin/rm -rf

all: $(LODIR)/set.o

test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/settest.o $(ODIR)/set.o
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/set.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@

$(LODIR)/set.o: $(SDIR)/*.c $(SDIR)/*.h
			$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
			$(RM) bin/* tbin/* $(LODIR)/*

$(OTDIR)/settest.o: $(TDIR)/*.c
			$(CC) -c $(CFLAGS) $^ -o $@
