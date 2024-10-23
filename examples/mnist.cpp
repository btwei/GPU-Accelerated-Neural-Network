#include "data_loader.h"
#include "neural_network.h"
#include "layers.h"

int main() {
    // Validate and load MNIST dataset
    if(){

    }

    neural_network nn;

    nn.addLayer(LinearLayer(100, 16));
    nn.addLayer(ReLU());
    nn.addLayer(LinearLayer(16, 16));
    nn.addLayer(ReLU());
    nn.addLayer(LinearLayer(16, 9));

    nn.train();

    return 0;
}