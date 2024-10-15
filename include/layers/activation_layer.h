#ifndef ACTIVATION_LAYER_H
#define ACTIVATION_LAYER_H

#include "layer.h"

class ReLU : public Layer {
    void forward();
    void backward();
};

class Sigmoid : public Layer {
    void forward();
    void backward();
};

#endif