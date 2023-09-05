CXX=g++
CXXFLAGS=-Wall -Wextra
SRC=main.cpp
BINS=$(SRC:.cpp=)

all: $(BINS)

$(BINS):
	$(CXX) $(CXXFLAGS) $(BINS).cpp -o $(BINS)

clean:
	rm -f $(BINS)
