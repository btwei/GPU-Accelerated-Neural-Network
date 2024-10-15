#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>

#include "layer.h"

class neural_network {
public:
    ~neural_network();

    void addLayer(Layer*);
    void train();
private:
    std::vector<Layer*> layerStack;
};

#endif