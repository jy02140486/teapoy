FILES:=$(shell ls)
$(shell touch zz)
FILES:=$(filter %.cc,$(FILES))
OBJECTS:=$(FILES:cc=o)
CC=g++
CFLAGS=-g -Wall
PACKAGES = clanCore-2.1 clanDisplay-2.1 clanApp-2.1 clanGL-2.1 clanGUI-2.1
LINKLIB   = -lpthread -lbox2d
LIBS = `pkg-config --libs $(PACKAGES)`

Main:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o Main $(LIBS) $(LINKLIB)
include zz
