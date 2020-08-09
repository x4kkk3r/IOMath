#include "../include/IOMath/types/vectors/TVector2.hpp"
#include "../include/IOMath/types/vectors/TVector3.hpp"
#include "../include/IOMath/types/vectors/TVector4.hpp"

using namespace IOMath::Types;

template <typename T>
void AssertVector(TVector<2, T> const &vector, T value)
{
    assert(vector.x == value);
    assert(vector.y == value);
}
template <typename T>
void AssertVector(TVector<3, T> const &vector, T value)
{
    assert(vector.x == value);
    assert(vector.y == value);
    assert(vector.z == value);
}
template <typename T>
void AssertVector(TVector<4, T> const &vector, T value)
{
    assert(vector.x == value);
    assert(vector.y == value);
    assert(vector.z == value);
    assert(vector.w == value);
}

template <typename T>
void AssertVector(TVector<2, T> const &vector, T x, T y)
{
    assert(vector.x == x);
    assert(vector.y == y);
}
template <typename T>
void AssertVector(TVector<3, T> const &vector, T x, T y, T z)
{
    assert(vector.x == x);
    assert(vector.y == y);
    assert(vector.z == z);
}
template <typename T>
void AssertVector(TVector<4, T> const &vector, T x, T y, T z, T w)
{
    assert(vector.x == x);
    assert(vector.y == y);
    assert(vector.z == z);
    assert(vector.w == w);
}