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

MathClasses::Vector2 min(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { min(a.x, b.x), min(a.y, b.y) };
}

MathClasses::Vector2 max(const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return { max(a.x, b.x), max(a.y, b.y) };
}

// CLAMPS

constexpr float clamp(float t, float a, float b)
{
	return max(a, min(b, t));
}

MathClasses::Vector2 clamp(const MathClasses::Vector2& t, const MathClasses::Vector2& a, const MathClasses::Vector2& b)
{
	return max(a, min(b, t));
}



//// Simple axis-aligned bounding box that stores min/max points
//struct AABB {
//
//	AABB() {}
//
//	AABB(const MathClasses::Vector2& min, const MathClasses::Vector2& max) : min(min), max(max) {}
//
//	MathClasses::Vector2 min, max;
//
//	// Find center of box
//	MathClasses::Vector2 Center() const
//	{
//		return (min + max) * 0.5f;
//	}
//
//	// Calc half extents
//	MathClasses::Vector2 Extents() const
//	{
//		return { abs(max.x - min.x) * 0.5f, 
//				abs(max.y - min.y) * 0.5f };
//	}
//
//	// Return corners (4 corners in 2d)
//	std::vector<MathClasses::Vector2> GetCorners() const
//	{
//		std::vector<MathClasses::Vector2> corners(4);
//		corners[0] = min;
//		corners[1] = { min.x, max.y };
//		corners[2] = max;
//		corners[3] = { max.x, min.y };
//		return corners;
//	}
//
//	//Fit an AABB around a set of points
//	void Fit(const MathClasses::Vector2* points, unsigned int count)
//	{
//		// invalidate extents
//		min = { FLT_MAX, FLT_MAX };
//		max = { -FLT_MAX, -FLT_MAX };
//
//		// Find min and max of the points
//		for (unsigned int i = 0; i < count; ++i, ++points)
//		{
//			min = ::min(min, *points);
//			max = ::max(max, *points);
//		}
//	}
//
//	void Fit(const std::vector<MathClasses::Vector2>& points)
//	{
//		min = { FLT_MAX, FLT_MAX };
//		max = { -FLT_MAX, -FLT_MAX };
//
//		for (auto& p : points)
//		{
//			min = ::min(min, p);
//			max = ::max(max, p);
//		}
//	}
//	
//	// is point within range of min and max corners?
//	bool Overlaps(const MathClasses::Vector2& p) const
//	{
//		return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
//	}
//
//	// If min of first box is gretaer than max of second box or max of first box less than min of second box, no overlap
//	bool Overlaps(const AABB& other) const
//	{
//		return !(max.x < other.min.x || max.y < other.min.y || min.x > other.max.x || min.y > other.max.y);
//	}
//
//	MathClasses::Vector2 ClosestPoint(const MathClasses::Vector2& p) const
//	{
//		return clamp(p, min, max);
//	}
//	
//	void 
//
//
//	
//};