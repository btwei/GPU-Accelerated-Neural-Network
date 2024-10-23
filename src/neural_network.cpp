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

void neural_network::train(int epochs, int miniBatchSize) {
    //Validate dataloader and layer compatibilities?

    //Create and Randomize Weights & Biases
    srand(time(nullptr));

    for(const auto& layer : layerStack){
        size_t numLayerWeights = layer->getSizeOut() * (layer->getSizeIn() + 1);
        weights.reserve(weights.size() + numLayerWeights);
        for(int i = 0; i < numLayerWeights; i++) {
            float randomInit = static_cast<float> ( rand() / static_cast<float>(RAND_MAX)) * 2 - 1.0f;
            weights.push_back(randomInit);
        }
    }

    //Load them onto the gpu

    //Loop through minibatches and do SGD
    //On CPU: pre-compute mini batches while gpu is processing
    //On GPU: 
    for(int i=0; i< epochs; i++){

    }

    //Unload data from the gpu
}

void neural_network::test() {
    
}

void neural_network::infer() {
    
}

void neural_network::saveModel() {
    
}

void neural_network::loadModel() {
    
}