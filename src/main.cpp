#include "data_loader.h"
#include "neural_network.h"
#include "linear_layer.h"
#include "activation_layer.h"

int main() {

    neural_network nn;

    nn.addLayer(new LinearLayer(100, 16));
    nn.addLayer(new ReLU());
    nn.addLayer(new LinearLayer(16, 16));
    nn.addLayer(new ReLU());
    nn.addLayer(new LinearLayer(16, 9));

    nn.train();

    return 0;
}