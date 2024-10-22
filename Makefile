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

.PHONY: all mnist clean

all: $(EXE) mnist

mnist: datasets/train-images-idx3-ubyte datasets/train-labels-idx1-ubyte datasets/t10k-images-idx3-ubyte datasets/t10k-labels-idx1-ubyte

datasets/train-images-idx3-ubyte:
	mkdir -p datasets
	wget -P datasets https://ossci-datasets.s3.amazonaws.com/mnist/train-images-idx3-ubyte.gz
	gzip -f -d datasets/train-images-idx3-ubyte.gz

datasets/train-labels-idx1-ubyte:
	mkdir -p datasets
	wget -P datasets https://ossci-datasets.s3.amazonaws.com/mnist/train-labels-idx1-ubyte.gz
	gzip -f -d datasets/train-labels-idx1-ubyte.gz

datasets/t10k-images-idx3-ubyte:
	mkdir -p datasets
	wget -P datasets https://ossci-datasets.s3.amazonaws.com/mnist/t10k-images-idx3-ubyte.gz
	gzip -f -d datasets/t10k-images-idx3-ubyte.gz

datasets/t10k-labels-idx1-ubyte:
	mkdir -p datasets
	wget -P datasets https://ossci-datasets.s3.amazonaws.com/mnist/t10k-labels-idx1-ubyte.gz
	gzip -f -d datasets/t10k-labels-idx1-ubyte.gz

$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXE)

-include $(DEPS)