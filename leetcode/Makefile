CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -Wno-sign-compare 
SRCS := $(shell find . -type f -name '*.cpp')
PROGS := $(patsubst %.cpp,%,$(SRCS))

.PHONY: all clean

all: $(PROGS)

%: %.cpp
	@mkdir -p $(dir $@)
	-$(CXX) $(CXXFLAGS) $< -o $@ -lm

clean:
	$(RM) -r $(PROGS)