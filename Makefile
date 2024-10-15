EXE := gpu_nn_framework

SRC_DIR := src
OBJ_DIR := build
INC_DIR := include

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c' -or -name '*.s' -or -name '*.cu')
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CXX := g++
CXXFLAGS := -Wall -Werror
CPPFLAGS := -I$(INC_DIR) -Iinclude/layers -Iinclude/utils -MMD -MP

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXE)

-include $(DEPS)