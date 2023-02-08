#include "Vertex.h"

void Vertex::setPosition(Vec3 p) {
    pos = p;
}

void Vertex::setColor(Color3 c) {
    color = c;
}

void Vertex::setIndex(unsigned int i) {
    index = i;
}

std::vector<double> Vertex::array() {
    std::vector<double> data;
    data.insert(data.end(), pos.begin(), pos.end());
    data.insert(data.end(), color.begin(), color.end());
    return data;
}

size_t Vertex::dataSize() {
    return sizeof(pos) + sizeof(color);
}
