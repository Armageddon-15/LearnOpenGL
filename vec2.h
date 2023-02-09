#ifndef VEC2
#define VEC2

class Vec2
{
public:
	double e[2];
	Vec2() : e{ 0, 0 } {}
	Vec2(double e0, double e1) : e{ e0, e1 } {}
	Vec2(double ee) : e{ ee, ee } {}

	double x() {
		return e[0];
	}
	double y() {
		return e[1];
	}

	double r() {
		return e[0];
	}
	double g() {
		return e[1];
	}

	double* begin() {
		return e;
	}

	double* end() {
		return e + 2;
	}

	size_t size() {
		return sizeof(Vec2);
	}

	size_t length() {
		return 2;
	}

};




#endif // !VEC2
