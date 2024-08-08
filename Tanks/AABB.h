#pragma once

#include "Vector2.h"
#include <vector>
#include "Utils.h"
#include "Matrix2.h"

// Axis-aligned bounding box
struct AABB
{
	MathClasses::Vector2 min;
	MathClasses::Vector2 max;

	AABB() {}
	AABB(const MathClasses::Vector2& min, const MathClasses::Vector2& max) : min(min), max(max) {}

	// Find Center of Box
	MathClasses::Vector2 Center() const
	{
		return (min + max) * 0.5f;
	}

	// Find Extents of Box
	MathClasses::Vector2 Extents() const
	{
		return (max - min) * 0.5f;
	}

	// Return Corners of Box
	std::vector<MathClasses::Vector2> Corners() const
	{
		std::vector<MathClasses::Vector2> corners(4);
		corners[0] = min;
		corners[1] = MathClasses::Vector2(max.x, min.y);
		corners[2] = max;
		corners[3] = MathClasses::Vector2(min.x, max.y);

		return corners;
	}

	// Given a set of points, calc bounding region and fit AABB to it
	void Fit(const MathClasses::Vector2* points, unsigned int count)
	{
		//invalidate extents
		min = MathClasses::Vector2(FLT_MAX, FLT_MAX);
		max = MathClasses::Vector2(-FLT_MAX, -FLT_MAX);

		//find min and max of the points
		for (unsigned int i = 0; i < count; ++i, ++points)
		{
			min = ::min(min, points[i]);
			max = ::max(max, points[i]);
		}
	}

	void Fit(const std::vector<MathClasses::Vector2>& points)
	{
		//invalidate extents
		min = MathClasses::Vector2(FLT_MAX, FLT_MAX);
		max = MathClasses::Vector2(-FLT_MAX, -FLT_MAX);

		//find min and max of the points
		for (auto& p : points)
		{
			min = ::min(min, p);
			max = ::max(max, p);
		}
	}

	// Check if point is inside box

	bool Overlaps(const MathClasses::Vector2& point) const
	{
		// Check if point is outside of box
		if (point.x < min.x || point.x > max.x) return false;
		if (point.y < min.y || point.y > max.y) return false;

		return true;
	}

	bool Overlaps(const AABB& other) const
	{
		// Exit with no intersection if separated along an axis
		if (max.x < other.min.x || min.x > other.max.x) return false;
		if (max.y < other.min.y || min.y > other.max.y) return false;

		// Overlapping on all axes means AABBs are intersecting
		return true;
	}



	//Find closest point on box to another point
	MathClasses::Vector2 ClosestPoint(const MathClasses::Vector2& point) const
	{
		// Clamp point to be inside box
		return ::clamp(point, min, max);
	}


	// set to transform of AABB
	void SetTransform(const MathClasses::Matrix2& transform)
	{
		std::vector<MathClasses::Vector2> corners = Corners();
		for (auto& corner : corners)
		{
			corner = transform * corner; //added method to multiply matrix by vector2
		}

		Fit(corners);
	}

};