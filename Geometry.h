#ifndef GEOMETRY
#define GEOMETRY

#include "Vertex.h"
#include "TriangleOrder.h"

class Geometry
{
public:
	size_t max_vertex_count;
	GLuint vao;
	std::vector<Vertex> vertices;
	std::vector<TriangleOrder> order;
	Geometry() : max_vertex_count(0), vao(0) {};

public:
	void addVertex(Vertex v);
	void deleteVertex(size_t pos);
	void clearVertices();
	Vertex& vertexAt(size_t pos);

	void addOrder(TriangleOrder t);
	void deleteOrder(size_t pos);
	void clearOrders();
	TriangleOrder& OrderAt(size_t pos);
	unsigned int orderSize();

	void bindVAO(GLuint& vao);
	void bindVBO(GLuint& vbo);
	void bindEBO(GLuint& ebo);
	void setBufferData();
	void use();
	void drawTriangle();
	
};

#endif // !GEOMETRY
