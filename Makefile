# 5/11/2012 Roger Banks
#
# Mostly borrowed from:
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#
# For future inhancements:
# http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-gcc-unix
# OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# HEADERS = $(wildcard *.h)
#
# Changes:
# 12 May 12 Added CFLAGS and LFLAGS macros. Added LIBS macro for future use of unit
#           test framework.

IDIR = ../include
ODIR = obj
LDIR = ../lib
LIBS = -lunit++
CC=g++
CFLAGS =-I${IDIR} -g -Wall
LFLAGS = -L${LDIR}
ODIR = obj
DEPS = knot.h my_functions.h
OBJ = knot.o th.o my_functions.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

th: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} ${LFLAGS}
	
.PHONY: clean

clean:
	rm -f *.o *~ core
