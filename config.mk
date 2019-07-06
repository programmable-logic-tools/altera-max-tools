
PREFIX ?= /usr/local
DESTDIR ?=
DEBUG ?= 1

CXX = clang++
CC = clang

C_STD = c99
CXX_STD = c++11
ifeq ($(DEBUG),1)
OPT_LEVEL = 0
DBG_LEVEL = -ggdb
else
OPT_LEVEL = 2
DBG_LEVEL =
endif
WARN_LEVEL = all

LDLIBS = -lm -lstdc++
CFLAGS += -MD -O$(OPT_LEVEL) $(DBG_LEVEL) -W$(WARN_LEVEL) -std=$(C_STD)
CFLAGS += -I$(PREFIX)/include
CXXFLAGS += -MD -O$(OPT_LEVEL) $(DBG_LEVEL) -W$(WARN_LEVEL) -std=$(CXX_STD)
CXXFLAGS += -I$(PREFIX)/include


%.o: %.c
	$(CC) -o $@ $(CFLAGS) $^

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $^
