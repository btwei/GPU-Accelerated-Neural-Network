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