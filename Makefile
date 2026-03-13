CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -I./core -I./bitstream -I./huffman
TARGET = compressor

SRCS = main.cpp \
       $(wildcard core/*.cpp) \
       $(wildcard bitstream/*.cpp) \
       $(wildcard huffman/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)