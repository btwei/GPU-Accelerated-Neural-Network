#include "neural_network.h"

neural_network::~neural_network() {
    //Clean-up layer objects
    for(auto& layer : layerStack){
        delete layer;
    }
}

void neural_network::addLayer(Layer* layer) {
    layerStack.push_back(layer);
}

void neural_network::train() {
    
}