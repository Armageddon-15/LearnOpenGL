#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;


class Vec3
{
	public:
		double e[3];
		Vec3() : e{0, 0, 0}{}
		Vec3(double e0, double e1, double e2): e{e0, e1, e2}{}
		Vec3(double ee) : e{ee, ee, ee} {}

		double x() {
			return e[0];
		}
		double y() {
			return e[1];
		}
		double z() {
			return e[2];
		}

		double r() {
			return e[0];
		}
		double g() {
			return e[1];
		}
		double b() {
			return e[2];
		}

		double* begin() {
			return e;
		}

		double* end() {
			return e + 3;
		}

		size_t size() {
			return sizeof(Vec3);
		}

		Vec3 operator-() const {
			return Vec3(-e[0], -e[1], -e[2]);
		}

		double operator[](int i) const {
			return e[i];
		}
		double& operator[](int i) {
			return e[i];
		}

		Vec3& operator+=(const Vec3& v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		Vec3& operator+=(const double t) {
			e[0] += t;
			e[1] += t;
			e[2] += t;
			return *this;
		}

		Vec3& operator-=(const Vec3& v) {
			e[0] -= v.e[0];
			e[1] -= v.e[1];
			e[2] -= v.e[2];
			return *this;
		}
		Vec3& operator-=(const double t) {
			e[0] -= t;
			e[1] -= t;
			e[2] -= t;
			return *this;
		}

		Vec3& operator*=(const Vec3& v) {
			e[0] *= v.e[0];
			e[1] *= v.e[1];
			e[2] *= v.e[2];
			return *this;
		}
		Vec3& operator*=(const double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		Vec3& operator/=(const double t) {
			return *this *= 1 / t;
		}
		// we cannot divide vector by a vector

		double length_squared() const {
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}

		double length() const {
			return sqrt(length_squared());
		}

		Vec3 normalized() const{
			return Vec3(e[0] / length(), e[1] / length(), e[2] / length());
		}

        bool near_zero() const {
            const double s = 1e-8f;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }

};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
	return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}
inline Vec3 operator+(const double t, const Vec3& v) {
	return Vec3(t + v.e[0], t + v.e[1], t + v.e[2]);
}
inline Vec3 operator+(const Vec3& v, const double t) {
	return t + v;
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}
inline Vec3 operator-(const double t, const Vec3& v) {
	return Vec3(t - v.e[0], t - v.e[1], t - v.e[2]);
}
inline Vec3 operator-(const Vec3& v, const double t) {
	return t + -v;
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}
inline Vec3 operator*(const double t, const Vec3& v) {
	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}
inline Vec3 operator*(const Vec3& v, const double t) {
	return t * v;
}

inline Vec3 operator/(const Vec3& v, const double t) {
	return (1 / t) * v;
}
// scalar cannot be divided by a vector

inline double dot(const Vec3& u, const Vec3& v) {
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 reflect(const Vec3 &ray, const Vec3 &normal) {
    return ray - 2 * dot(ray, normal) * normal;
}

inline Vec3 refract(const Vec3 &ray_dir, const Vec3 &normal, const double refractive_ratio) {
    //return the refracted ray
    //refractive_ratio is incident/refract
    double cos_theta = dot(-ray_dir, normal);
    Vec3 ray_perp = refractive_ratio * (ray_dir + cos_theta * normal);
    Vec3 ray_parallel = -sqrt(1 - ray_perp.length_squared()) * normal;

    return ray_parallel + ray_perp;
}

inline Vec3 normalize(const Vec3& v) {
	return v.normalized();
}


using Point3 = Vec3;
using Color3 = Vec3;

#endif