
include ../config.mk

TARGET = pof2svf
SRCS = $(wildcard *.cpp ../common/*.cpp ../common/svf/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS += -I../common
CXXFLAGS += -I../common/svf


all: $(TARGET)

run: $(TARGET)
	./$^

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^ 

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
