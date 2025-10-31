CXX = g++
CXXFLAGS = -std=c++17
SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
TARGET = gorun

# Use .PHONY to force a rebuild if any SRCS or HEADERS change.
.PHONY: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
