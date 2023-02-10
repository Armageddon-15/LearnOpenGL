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
    appendDataToVector(data, pos);
    appendDataToVector(data, color);
    appendDataToVector(data, uv0);
    return data;
}

size_t Vertex::dataSize() {
    return sizeof(pos) + sizeof(color);
}

void Vertex::setUV0(Vec2 uv) {
    uv0 = uv;
}
