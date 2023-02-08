#ifndef VERTEX
#define VERTEX

#include "OpenGLHepler.h"
#include "vec3.h"

#include <vector>

class Vertex
{
public:
	Vec3 pos;
	Vec3 color;
	unsigned int index;
	Vertex(): index(0), pos(Vec3(0, 0, 0)), color(Color3(0, 0, 0)) {}
	Vertex(Vec3 p, Color3 c) : index(0), pos(p), color(c) {}

public:
	void setPosition(Vec3 p);
	void setColor(Color3 c);

	void setIndex(unsigned int i);

	std::vector<double> array();
	size_t dataSize();
};


#endif // !VERTEX
