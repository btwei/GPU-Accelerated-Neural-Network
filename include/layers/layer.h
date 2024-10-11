#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    virtual void forward();
    virtual void backward();
    virtual ~Layer() {};
protected:
    std::vector<float> parameters;
};

#endif