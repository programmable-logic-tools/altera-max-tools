
include ../config.mk

TARGET = pofunpack
SRCS = $(wildcard *.cpp ../common/*.cpp ../common/pof/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS += -I../common
CXXFLAGS += -I../common/pof


all: $(TARGET)

run: $(TARGET)
	./$^

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^ 

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
