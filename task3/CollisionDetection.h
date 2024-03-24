#include <vector>
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

inline constexpr double eps{ 10e-12 };
inline constexpr double M_PI{ 3.1415926535897932384626433832795 };
struct vec2
{
    double x, y;
};

struct triangle
{
    std::array<vec2, 3> points;
};

constexpr double mat_det2x2(const vec2& p1, const vec2& p2, const vec2& p3)
{
    return ((p1.x - p3.x) * (p2.y - p3.y) - (p1.y - p3.y) * (p2.x - p3.x));
}

constexpr double vectorNorm(const vec2& vec1, const vec2& vec2)
{
    return vec1.x * vec2.y + vec1.x * vec2.y;
}

constexpr double crossProduct(const vec2& A, const vec2& B)
{
    return A.x * B.y - B.x * A.y;
}

constexpr double dotProduct(const vec2& A, const vec2& B)
{
    return A.x * B.x + A.y * B.y;
}


bool isPointInsideTriangle(const triangle& triangle1, const vec2& vec2);
bool areEdgesColliding(const vec2& A, const vec2& B, const vec2& C, const vec2& D);
bool isColliding(const triangle& triangle1, const triangle& triangle2);