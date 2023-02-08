#ifndef TRIANGLEODER
#define TRIANGLEODER

class TriangleOrder
{
public:
	unsigned int e[3];
	TriangleOrder() : e{ 0, 0, 0 } {}
	TriangleOrder(unsigned int e0, unsigned int e1, unsigned int e2) : e{ e0, e1, e2 } {}
	TriangleOrder(unsigned int ee) : e{ ee, ee, ee } {}

public:
	unsigned int* begin() {
		return e;
	}

	unsigned int* end() {
		return e + 3;
	}

	size_t size() {
		return 3;
	}
};

#endif // !TRIANGLEODER



