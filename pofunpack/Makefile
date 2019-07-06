
include ../config.mk

SRCS = $(wildcard *.cpp ../common/*.cpp ../common/pof/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS += -I../common
CXXFLAGS += -I../common/pof


all: pofunpack

run: pofunpack
	./$^

pofunpack: $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^ 

clean:
	rm -f $(OBJS) pofunpack

.PHONY: all clean
