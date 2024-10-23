#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
public:
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Layer() = default;
    inline int getSizeIn() const { return mSizeIn; }
    inline int getSizeOut() const { return mSizeOut; }
protected:
    int mSizeIn = 0;
    int mSizeOut = 0;
};

#endif