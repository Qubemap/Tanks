#pragma once

#pragma once
#include <string>
#include <cmath>

namespace MathClasses
{
	struct Vector2
	{
		union
		{
			struct { float x, y; };
			float data[2];
		};

		Vector2() : x{ 0 }, y{ 0 }
		{
		}

		Vector2(float X, float Y) : x{ X }, y{ Y }
		{
		}

		float& operator [](int dim)
		{
			return data[dim];
		}

		const float& operator [](int dim) const
		{
			return data[dim];
		}

		operator float* () { return data; }

		operator const float* () const { return data; }

		//adding vector (0, 2, 0) to another would shift the point up two units for example
		Vector2 operator +(const Vector2& rhs) const
		{
			Vector2 sum;

			//x is the LEFT vectors x-component
			//rhs.x is the RIGHT vectors x-component
			sum.x = x + rhs.x;
			sum.y = y + rhs.y;

			return sum;
		}

		Vector2 operator -(const Vector2& rhs) const
		{
			Vector2 diff;

			diff.x = x - rhs.x;
			diff.y = y - rhs.y;

			return diff;
		}

		//if scalar is two, vector would be doubled. (2, 4, -2) becomes (4, 8, -4) 
		Vector2 operator *(const float& scalar) const
		{
			Vector2 scaled;

			scaled.x = x * scalar;
			scaled.y = y * scalar;

			return scaled;
		}

		friend Vector2 operator*(const float& lhs, const Vector2& rhs)
		{
			return rhs * lhs;
		}

		Vector2 operator /(const float& div) const
		{
			Vector2 quot;

			quot.x = x / div;
			quot.y = y / div;

			return quot;
		}

		void operator +=(const Vector2& rhs)
		{
			x = x + rhs.x;
			y = y + rhs.y;
		}

		void operator -=(const Vector2& rhs)
		{
			x = x - rhs.x;
			y = y - rhs.y;
		}


		void operator *=(const float& scalar)
		{
			x = x * scalar;
			y = y * scalar;
		}

		void operator *=(const Vector2& rhs)
		{
			x = x * rhs.x;
			y = y * rhs.y;
		}

		void operator /=(const Vector2& rhs)
		{
			x = x / rhs.x;
			y = y / rhs.y;
		}

		bool operator == (const Vector2& rhs) const
		{
			float xDist = fabsf(x - rhs.x);
			float yDist = fabsf(y - rhs.y);

			const float THRESHOLD = 0.00001f;

			return xDist < THRESHOLD && yDist < THRESHOLD;
		}

		bool operator !=(const Vector2& rhs) const
		{
			return !(*this == rhs);
		}

		std::string ToString() const
		{
			return std::to_string(x) + ", " + std::to_string(y);
		}

		//length of a vector
		float Magnitude() const
		{
			//return square root of all values to the power of 2 (distance formula pythag)
			return sqrtf(x * x + y * y);
		}

		//doesn't return actual distance, only used to determine if farther than another call of this function.
		float MagnitudeSqr() const
		{
			return x * x + y * y;
		}

		//Normalises the Vector (sets magnitude to 1 unit). think the 3 colored arrows in 3d software
		void Normalise()
		{
			float m = Magnitude();

			if (m == 0)
			{
				x = 0;
				y = 0;
				return;
			}

			x /= m;
			y /= m;
		}

		//Returns a normalised copy of the vector
		Vector2 Normalised() const
		{
			Vector2 copy = *this;
			copy.Normalise();

			return copy;
		}

		//Dot and cross product

		//dot returns difference in angle. 1 
		const float Dot(const Vector2& other) const
		{
			return x * other.x + y * other.y;
		}

		/*Vector2 Cross(const Vector2& other)
		{
			return Vector2(y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x);
		}*/

		float AngleBetween(const Vector2& other) const
		{
			//normalise the vectors
			const Vector2 a = Normalised();
			const Vector2 b = other.Normalised();

			//calculate the dot product
			float d = a.Dot(other);

			//return the angle between them
			return acosf(d);
		}
	};
};
