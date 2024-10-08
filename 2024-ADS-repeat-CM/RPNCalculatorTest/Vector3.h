#pragma once
#include <iostream>
#include <cmath>
#include <string>

//operater overload https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-170

using namespace std;

    class Vector3
    {
    public:
        float x;
        float y;
        float z;

        // Default constructor
        Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

        // Parameterized constructor
        Vector3(float x, float y, float z) : x(x), y(y), z(z) {}


       friend bool operator==(const Vector3& lhs, const Vector3& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}


    };

