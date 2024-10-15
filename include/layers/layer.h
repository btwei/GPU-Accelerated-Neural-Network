#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Layer() = default;
protected:
    std::vector<float> parameters;
};

#endif