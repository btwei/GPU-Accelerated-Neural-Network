#ifndef LINEAR_LAYER_H
#define LINEAR_LAYER_H

class LinearLayer : public Layer {
public:
    LinearLayer(int sizeIn, int sizeOut);
    void forward();
    void backward();
private:
    int m_sizeIn;
    int m_sizeOut;
};

#endif