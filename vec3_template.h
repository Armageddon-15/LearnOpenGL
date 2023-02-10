#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

template <typename T>
class Vec3T
{
	public:
		T e[3];
		Vec3T() : e{0, 0, 0}{}
		Vec3T(T e0, T e1, T e2): e{e0, e1, e2}{}
		Vec3T(T ee) : e{ee, ee, ee} {}

		T x() {
			return e[0];
		}
		T y() {
			return e[1];
		}
		T z() {
			return e[2];
		}

		T r() {
			return e[0];
		}
		T g() {
			return e[1];
		}
		T b() {
			return e[2];
		}

		T* begin() {
			return e;
		}

		T* end() {
			return e + 3;
		}

		size_t size() {
			return sizeof(Vec3T);
		}

		Vec3T operator-() const {
			return Vec3T(-e[0], -e[1], -e[2]);
		}

		T operator[](int i) const {
			return e[i];
		}
		T& operator[](int i) {
			return e[i];
		}

		Vec3T& operator+=(const Vec3T& v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		Vec3T& operator+=(const T t) {
			e[0] += t;
			e[1] += t;
			e[2] += t;
			return *this;
		}

		Vec3T& operator-=(const Vec3T& v) {
			e[0] -= v.e[0];
			e[1] -= v.e[1];
			e[2] -= v.e[2];
			return *this;
		}
		Vec3T& operator-=(const T t) {
			e[0] -= t;
			e[1] -= t;
			e[2] -= t;
			return *this;
		}

		Vec3T& operator*=(const Vec3T& v) {
			e[0] *= v.e[0];
			e[1] *= v.e[1];
			e[2] *= v.e[2];
			return *this;
		}
		Vec3T& operator*=(const T t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		// cannot divide vector by a vector
		Vec3T& operator/=(const T t) {
			return *this *= 1 / t;
		}

		T length_squared() const {
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}

		T length() const {
			return sqrt(length_squared());
		}

		Vec3T normalized() const{
			return Vec3T(e[0] / length(), e[1] / length(), e[2] / length());
		}

        bool near_zero() const {
            const T s = 1e-8f;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }

};

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Vec3T<T>& v) {
	return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

template <typename T>
inline Vec3T<T> operator+(const Vec3T<T>& u, const Vec3T<T>& v) {
	return Vec3T<T>(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

template <typename T>
inline Vec3T<T> operator+(const T t, const Vec3T<T>& v) {
	return Vec3T<T>(t + v.e[0], t + v.e[1], t + v.e[2]);
}

template <typename T>
inline Vec3T<T> operator+(const Vec3T<T>& v, const T t) {
	return t + v;
}

template <typename T>
inline Vec3T<T> operator-(const Vec3T<T>& u, const Vec3T<T>& v) {
	return Vec3T<T>(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

template <typename T>
inline Vec3T<T> operator-(const T t, const Vec3T<T>& v) {
	return Vec3T<T>(t - v.e[0], t - v.e[1], t - v.e[2]);
}

template <typename T>
inline Vec3T<T> operator-(const Vec3T<T>& v, const T t) {
	return t + -v;
}

template <typename T>
inline Vec3T<T> operator*(const Vec3T<T>& u, const Vec3T<T>& v) {
	return Vec3T<T>(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

template <typename T>
inline Vec3T<T> operator*(const T t, const Vec3T<T>& v) {
	return Vec3T<T>(t * v.e[0], t * v.e[1], t * v.e[2]);
}

template <typename T>
inline Vec3T<T> operator*(const Vec3T<T>& v, const T t) {
	return t * v;
}

// scalar cannot be divided by a vector
template <typename T>
inline Vec3T<T> operator/(const Vec3T<T>& v, const T t) {
	return (1 / t) * v;
}

template <typename T>
inline T dot(const Vec3T<T>& u, const Vec3T<T>& v) {
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

template <typename T>
inline Vec3T<T> cross(const Vec3T<T>& u, const Vec3T<T>& v) {
    return Vec3T<T>(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

template <typename T>
inline Vec3T<T> normalize(const Vec3T<T>& v) {
	return v.normalized();
}

#endif