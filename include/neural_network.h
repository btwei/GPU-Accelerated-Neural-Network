#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <cstdlib>
#include <ctime>
#include <vector>

#include "layers.h"

class neural_network {
public:
    ~neural_network();

    void addLayer(Layer);
    void train(int epochs, int miniBatchSize);
    void test();
    void infer();
    void saveModel();
    void loadModel();
private:
    std::vector<Layer> layerStack;
    std::vector<float> weights;
};

#endif