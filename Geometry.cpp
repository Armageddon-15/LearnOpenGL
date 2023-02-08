#include "Geometry.h"

void Geometry::addVertex(Vertex v) {
	if (vertices.size() <= max_vertex_count) {
		vertices.push_back(v);
	} else {
		vertices.at(max_vertex_count) = v;
	}
	max_vertex_count += 1;
}

void Geometry::deleteVertex(size_t pos) {
	vertices.erase(vertices.begin() + pos);
	max_vertex_count -= 1;
}

void Geometry::clearVertices() {
	vertices.clear();
	max_vertex_count = 0;
}

Vertex& Geometry::vertexAt(size_t pos) {
	return vertices.at(pos);
}

void Geometry::addOrder(TriangleOrder t) {
	order.push_back(t);
}

void Geometry::deleteOrder(size_t pos) {
	order.erase(order.begin() + pos);
}

void Geometry::clearOrders() {
	order.clear();
}

TriangleOrder& Geometry::OrderAt(size_t pos) {
	return order.at(pos);
}

unsigned int Geometry::orderSize() {
	return order.size() * sizeof(TriangleOrder);
}

void Geometry::bindVAO(GLuint& v) {
	glBindVertexArray(v);
	vao = v;
}

void Geometry::bindVBO(GLuint& vbo) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	std::vector<double> data_array;
	for (Vertex v : vertices) {
		auto b = v.array();
		data_array.insert(data_array.end(), b.begin(), b.end());
	}
	glBufferData(GL_ARRAY_BUFFER, data_array.size() * sizeof(double), data_array.data(), GL_STATIC_DRAW);
}

void Geometry::bindEBO(GLuint& ebo) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	std::vector<unsigned int> ord_array;
	for (TriangleOrder t : order) {
		ord_array.insert(ord_array.end(), t.begin(), t.end());
	}
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ord_array.size() * sizeof(unsigned int), ord_array.data(), GL_STATIC_DRAW);
}

void Geometry::setBufferData() {
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 2*sizeof(Vec3), 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, 2*sizeof(Vec3), (void*)sizeof(Vec3));
	glEnableVertexAttribArray(1);
}

void Geometry::use() {
	glBindVertexArray(vao);
}

