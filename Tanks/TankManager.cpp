#include "TankManager.h"
#include "raylib-cpp.hpp"

void TankManager::OnUpdate(float deltaTime)
{
	float MODIFIER = 2;
	MathClasses::Vector3 in(MODIFIER, MODIFIER, 1);

	MODIFIER = 0.5f;
	MathClasses::Vector3 out(MODIFIER, MODIFIER, 1);

	if (GetMouseWheelMove() > 0.0f)
	{
		Scale(in);
	}
	else if (GetMouseWheelMove() < 0.0f)
	{
		Scale(out);
	}
}