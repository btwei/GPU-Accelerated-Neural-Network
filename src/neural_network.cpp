#include "neural_network.h"

neural_network::~neural_network() {

}

void neural_network::addLayer(Layer layer) {
    layerStack.push_back(layer);
}

void neural_network::train(int epochs, int miniBatchSize) {
    //Validate dataloader and layer compatibilities? Verify if layers are all gpu implemented.

    //Create and Randomize Weights & Biases
    srand(time(nullptr));

    for(const auto& layer : layerStack){
        size_t numLayerWeights = layer.sizeOut * (layer.sizeIn + 1);
        weights.reserve(weights.size() + numLayerWeights);
        for(int i = 0; i < numLayerWeights; i++) {
            float randomInit = static_cast<float> ( rand() / static_cast<float>(RAND_MAX)) * 2 - 1.0f;
            weights.push_back(randomInit);
        }
    }

    //Load Weights, Biases, and layerStack onto the GPU

    //Loop through minibatches and do SGD
    //On CPU: pre-compute mini batches while gpu is processing
    //On GPU: do SGD based on model with given mini-batch
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