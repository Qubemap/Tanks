#pragma once

#include <vector>
#include "Vector2.h"
#include "Matrix3.h"


// As FLOATS
constexpr float min(float a, float b)
{
	return a < b ? a : b;
}

constexpr float max(float a, float b)
{
	return a > b ? a : b;
}

// As VECTORS

inline MathClasses::Vector2 min(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { min(a.x, b.x), min(a.y, b.y) };
}

inline MathClasses::Vector2 max(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { max(a.x, b.x), max(a.y, b.y) };
}

// CLAMPS

constexpr float clamp(float t, float a, float b)
{
	return max(a, min(b, t));
}

inline MathClasses::Vector2 clamp(const MathClasses::Vector2& t, const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return max(a, min(b, t));
}
