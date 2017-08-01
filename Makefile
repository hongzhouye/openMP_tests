CXX=icpc
CXXFLAGS=-std=c++11 -Wall -qopenmp #-O3
LDFLAGS=-Wl,-rpath,$(CONDA_PREFIX)/lib

%.o: %.cpp
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

%.x: %.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

clean:
	rm -f *.o *.x

#.PHONY: all clean
