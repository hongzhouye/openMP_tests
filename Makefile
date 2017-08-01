CXX=g++-6
CXXFLAGS=-std=c++11 -Wall -fopenmp
LDFLAGS=-Wl,-rpath,$(CONDA_PREFIX)/lib

%.o: %.cpp
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

%.x: %.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)

clean:
	rm -f *.o *.x

#.PHONY: all clean
