#include "layers.h"

Layer LinearLayer(int sizeIn, int sizeOut) {
    return {Layer::LayerType::LINEAR, sizeIn, sizeOut};
}

Layer ReLU() {
    return {Layer::LayerType::RELU, 0, 0};
}

Layer Sigmoid() {
    return {Layer::LayerType::SIGMOID, 0, 0};
}