CC = /usr/bin/gcc
CFLAGS = -Wall -g
CLIBFLAGS = -shared
SDIR = src
LDIR = lib
ODIR = bin
OTDIR = tbin
TDIR = test
INC = include
RM = /bin/rm -rf

all: $(LDIR)/libcstl.so
sub: $(ODIR)/*.o
test: $(OTDIR)/testexe

$(OTDIR)/testexe: $(OTDIR)/libtest.o $(LDIR)/libcstl.so
	$(CC) -L$(LDIR) $(CFLAGS) -o $@ $< -lcstl

$(ODIR)/*.o:
		$(MAKE) -C $(SDIR)

$(LDIR)/libcstl.so: $(ODIR)/*.o
			$(CC) $(CLIBFLAGS) -o $@ $^

.PHONY: clean

clean: $(SDIR)/*
			$(RM) lib/* tbin/* bin/*
			$(MAKE) -C $(SDIR) clean

$(OTDIR)/libtest.o: $(TDIR)/*.c
			$(CC) -I$(INC) -c $(CFLAGS) $^ -o $@
