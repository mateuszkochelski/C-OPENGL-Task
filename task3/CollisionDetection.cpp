#include "CollisionDetection.h"

bool isColliding(const triangle& triangle1, const triangle& triangle2)
{
    static constexpr auto pointsInTriangle{ 3 };
    for (int i{}; i < pointsInTriangle; ++i)
    {
        const auto isInFirstTriangle{ isPointInsideTriangle(triangle1, triangle2.points[i]) };
        const auto isInSecondTriangle{ isPointInsideTriangle(triangle2,triangle1.points[i]) };
        if (isInFirstTriangle || isInSecondTriangle)
            return true;
    }
    for (int i{}; i < pointsInTriangle; ++i)
        for (int j{}; j < pointsInTriangle; ++j)
        {
            if (areEdgesColliding(triangle1.points[i], triangle1.points[(i + 1) % 3], triangle2.points[j], triangle2.points[(j + 1) % 3]))
            {
                return true;
            }
        }
    return false;
}

bool isPointInsideTriangle(const triangle& triangle1, const vec2& vec2)
{
    int plusSigns{};
    int minusSigns{};

    static constexpr auto trianglePoints{ 3 };

    for (int i{}; i < trianglePoints; ++i)
    {
        const auto isInside{ mat_det2x2(triangle1.points[i], triangle1.points[(i + 1) % 3], vec2) > eps };
        if (isInside)
            plusSigns++;
        else
            minusSigns++;
    }

    static constexpr auto sameSidePoints{ 3 };
    return plusSigns == sameSidePoints || minusSigns == sameSidePoints;
}

bool areEdgesColliding(const vec2& A, const vec2& B, const vec2& C, const vec2& D)
{
    const vec2 AB{ B.x - A.x, B.y - A.y };
    const vec2 CD{ D.x - C.x, D.y - C.y };
    const vec2 AminusB{ C.x - A.x, C.y - A.y };

    const auto ABxCD{ crossProduct(AB, CD) };
    const auto AminusBxCD{ crossProduct(AminusB, CD) };
    const auto AminusBxAB{ crossProduct(AminusB, AB) };

    const auto isParralel{ abs(ABxCD) < eps };
    const auto isCollinear{ isParralel && (abs(AminusBxCD) < eps) };
    if (isParralel)
    {
        if (isCollinear)
        {
            const auto t0{ dotProduct(AminusB, AB) / dotProduct(AB, AB) };
            const auto t1{ t0 + dotProduct(CD, AB) / dotProduct(AB, AB) };

            const auto var1{ (0 <= t0 && t0 <= 1) };
            const auto var2{ (0 <= t1 && t1 <= 1) };
            const auto is_interval_t0_t1_intersecting_0_1 = var1 || var2;
            return (is_interval_t0_t1_intersecting_0_1);
        }
        return false;
    }
    const auto t{ crossProduct(AminusB, CD) / crossProduct(AB, CD) };
    const auto u{ crossProduct(AminusB, AB) / crossProduct(AB, CD) };

    const auto firstParamter{ 0 <= t && t <= 1 };
    const auto secondParameter{ 0 <= u && u <= 1 };
    return (firstParamter && secondParameter);
}
