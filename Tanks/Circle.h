#pragma once

#include "Utils.h"
#include "Vector2.h"

struct Circle {

	Circle() : center(), radius(0.0f) {}

	Circle(const MathClasses::Vector2& p, float r) : center(p), radius(r) {}

	MathClasses::Vector2 center;
	float radius;

	void Fit(const MathClasses::Vector2* points, unsigned int count)
	{
		// Invalidate Extents
		MathClasses::Vector2 min = { FLT_MAX, FLT_MAX };
		MathClasses::Vector2 max = { FLT_MIN, FLT_MIN };

		// find min and max of points
		for (unsigned int i = 0; i < count; ++i, ++points)
		{
			min = ::min(min, *points);
			max = ::max(max, *points);
		}

		// Put a circle around the min/max box
		center = (min + max) * 0.5f;
		radius = center.DistanceTo(max); //TODO

	}

	void Fit(const std::vector<MathClasses::Vector2>& points)
	{
		// invalidate extents
		MathClasses::Vector2 min = { FLT_MAX, FLT_MAX };
		MathClasses::Vector2 max = { FLT_MIN, FLT_MIN };

		// find min and max of the points
		for (auto& p : points) {
			min = ::min(min, p);
			max = ::max(max, p);
		}

		// put a circle around the min/max box
		center = (min + max) * 0.5f;
		radius = center.DistanceTo(max); //TODO
	}

	bool Overlaps(const MathClasses::Vector2& p) const
	{
		MathClasses::Vector2 toPoint = p - center;

		return toPoint.MagnitudeSqr() <= (radius * radius);
	}

	bool Overlaps(const Circle& other) const
	{
		MathClasses::Vector2 diff = center - other.center;

		return diff.MagnitudeSqr() <= ((radius + other.radius) * (radius + other.radius));
	}


	MathClasses::Vector2 ClosestPoint(const MathClasses::Vector2& p) const
	{
		// Distance from center
		MathClasses::Vector2 toPoint = p - center;
		
		// If outside of radius bring it back to the radius
		if (toPoint.MagnitudeSqr() > radius * radius)
		{
			toPoint = toPoint.Normalised() * radius;
		}

		return center + toPoint;

	}

	Circle operator =(const Circle other)
	{
		this->center = other.center;
		this->radius = other.radius;
	}

};