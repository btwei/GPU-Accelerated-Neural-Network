#ifndef LAYER_H
#define LAYER_H

struct Layer {
    enum LayerType { LINEAR, RELU, SIGMOID 
    };
    LayerType type;
    int sizeIn;
    int sizeOut;
};

Layer LinearLayer(int sizeIn, int sizeOut);

Layer ReLU();

Layer Sigmoid();

#endif