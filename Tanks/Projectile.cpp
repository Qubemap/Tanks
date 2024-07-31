#include "Projectile.h"

void Projectile::OnUpdate(float deltaTime)
{
	const float SPEED = 300.0f;

	MathClasses::Vector3 finalMove = GetForward() * (SPEED * deltaTime);

	Translate(finalMove);
}