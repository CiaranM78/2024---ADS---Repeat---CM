#pragma once
#include <iostream>
#include <cmath>

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

        // Overload the << operator for Vector3
        friend ostream& operator<<(std::ostream& os, const Vector3& v);

        bool operator==(const Vector3& other) const;


    };

