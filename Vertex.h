#ifndef VERTEX
#define VERTEX

#include "OpenGLHepler.h"
#include "vec3.h"
#include "vec2.h"

#include <vector>

class Vertex
{
public:
	Vec3 pos;
	Vec3 color;
	Vec2 uv0;
	unsigned int index;
	Vertex() : index(0), pos(Vec3(0, 0, 0)), color(Color3(0, 0, 0)), uv0(Vec2(0, 0)) {}
	Vertex(Vec3 p, Color3 c, Vec2 uv) : index(0), pos(p), color(c), uv0(uv) {}

public:
	void setPosition(Vec3 p);
	void setColor(Color3 c);
	void setUV0(Vec2 uv);

	void setIndex(unsigned int i);

	std::vector<double> array();
	size_t dataSize();
};


#endif // !VERTEX
