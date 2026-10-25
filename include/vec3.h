#pragma once

#include <cmath>
#include <iostream>

class vec3 {
    public:
       // Declaring a size-three array of doubles.
       double e[3];
 
       //A constructor for vec3
       vec3(): e{0,0,0} {
         //What happens in here only runs after the object is created
       }
       //Another constructor
       vec3(double e0, double e1, double e2): e{e0, e1, e2} {}
       // the const here is for clarity, these member functions do not modify the member variables. 
       double x() const { return e[0]; }
       double y() const { return e[1]; }
       double z() const { return e[2]; }

       vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]);}
       double operator[](int i) const { return e[i]; }
       // I suspect this allows me to edit using the [] notation, the first one is for once vec3 is constant, the latter is the non-const case.
       double& operator[](int i) { return e[i];}

       //This returns a reference to a vec3 object and takes in a read-only reference to a vec3 object    a += b;
       vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
       }

       vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this; //where *this refers to the original object the member function was called on 
       }

       vec3& operator/=(double t) {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
       }

       // This way of doing it is confusing, why do these two functions (perhaps we use length_squared later) and why not use ^ type notation
       double length() const {
        return std::sqrt(length_squared());
       }
       double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
       }


};

// useful alias
using point3 = vec3;

// Vector Utility functions

//std::ostream is a c++ type for an output stream, this lets you print a vector with << 
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}
//inline is useful when defining functions in several places like in a header file, we would get duplicate-definition linker errors otherwise

//lets you add vectors 
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0]+v.e[0],u.e[1]+v.e[1], u.e[2]+v.e[2]);
}

//subtracting vectors 
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0]-v.e[0], u.e[1]-v.e[1], u.e[2]-v.e[2]);
}

//element-wise product vectors
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//scalar * product vectors
inline vec3 operator*(double t, const vec3& u) {
    return vec3(u.e[0] * t, u.e[1] * t, u.e[2] * t);
}

inline vec3 operator*(const vec3& u,double t) {
    return t * u;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}
inline double dot(const vec3& v, const vec3& u) {
    // vec3 w = v*u;
    // return w.e[0] + w.e[1] + w.e[2];
    return v.e[0]*u.e[0] + v.e[1]*u.e[1] + v.e[2]*u.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], u.e[2] * v.e[0] - u.e[0] * v.e[2], u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

