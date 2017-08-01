CXX=g++-6
CXXFLAGS=-Wall

PROGS=prog-1

all: $(PROGS)

clean:
	rm -f *.o $(PROGS)

.PHONY: all clean
