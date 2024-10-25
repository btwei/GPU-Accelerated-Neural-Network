EX_DIR := examples
SRC_DIR := src
OBJ_DIR := build
INC_DIR := include

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c' -or -name '*.s' -or -name '*.cu') $(shell find $(EX_DIR) -name '*.cpp')
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CXX := g++
CXXFLAGS := -Wall -Werror
CPPFLAGS := -I$(INC_DIR) -Iinclude/utils -MMD -MP
LDFLAGS := -L/usr/local/cuda-12.6/lib64 -lcuda -lcudart

NVCC := nvcc
NVCCFLAGS :=

.PHONY: all clean

all: mnist

mnist: datasets/train-images-idx3-ubyte datasets/train-labels-idx1-ubyte datasets/t10k-images-idx3-ubyte datasets/t10k-labels-idx1-ubyte $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

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

$(OBJ_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.cu.o: %.cu
	mkdir -p $(dir $@)
	$(NVCC) $(CPPFLAGS) $(NVCCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) datasets

-include $(DEPS)