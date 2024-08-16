#include "pch.h"
#include "Vector3.h"

using namespace std;

ostream& operator<<(ostream& os, const Vector3& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

bool Vector3::operator==(const Vector3& other) const
{
    return (x == other.x && y == other.y && z == other.z);
}