#pragma once

#include "Vector3.h"

constexpr float min(float a, float b)
{
	return a < b ? a : b;
}

constexpr float max(float a, float b)
{
	return a > b ? a : b;
}

MathClasses::Vector2 min(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { (min(a.x, b.x), min(a.y, b.y)) };
}

MathClasses::Vector2 min(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { (max(a.x, b.x), max(a.y, b.y)) };
}