#include "../CollisionDetection.cpp"
#include "gtest/gtest.h"


TEST(TriangleCollisionsTesting, areTrianglesColliding) {
    triangle t1{ {vec2{0, 0}, {0,0.7}, {0.7, 0}} };
    triangle t2{ {vec2{0.5, 0.1}, {0.8, 0.8}, {0.1, 0.1}} };
    EXPECT_TRUE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTriangleInsideTriangleColliding) {
    triangle t1{ { vec2{0, 0}, {0,0.7}, {0.7, 0}} };
    triangle t2{ { vec2{0.10, 0.10}, {0.15,0.15}, {0.20, 0.10}} };
    EXPECT_TRUE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTrianglesCollidingByEdges) {
    triangle t1{ { vec2{-0.1, -0.1}, {0.1,0.1}, {0.3, -0.1}} };
    triangle t2{ { vec2{-0.2, 0}, {0.2,0.2}, {0.4, 0}} };
    EXPECT_TRUE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTrianglesWithCollinearEdgesNotColliding) {
    triangle t1{ { vec2{-0.1, -0.1}, {0.1,0.1}, {0.3, -0.1}} };
    triangle t2{ { vec2{0.5, 0.5}, {0.7,0.7}, {0.9, 0.5}} };
    EXPECT_FALSE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTrianglesNotCollidng) {
    triangle t1{ { vec2{0, 0}, {0,0.10}, {0.10, 0}} };
    triangle t2{ { vec2{0.5, 0.5}, {0.15,0.15}, {0.10, 0.5}} };
    EXPECT_FALSE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTrianglesNotCollidng2) {
    triangle t1{  { vec2{0, 0}, {0,10}, {10, 0}} };
    triangle t2{  { vec2{11, 11}, {15,15}, {20, 11}} };
    EXPECT_FALSE(isColliding(t1, t2));
}

TEST(TriangleCollisionsTesting, areTrianglesWithCollinearEdgeColliding) {
    triangle t1{  { vec2{-0.1, -0.1}, {0.1,0.1}, {0.1, -0.1}} };
    triangle t2{  { vec2{0, 0}, {0.2,0.2}, {0.2, 0}} };
    EXPECT_TRUE(isColliding(t1, t2));
}

int main()
{
    RUN_ALL_TESTS();
    std::cin.get();
}