#include "Projectile.h"

void Projectile::OnUpdate(float deltaTime)
{
	MathClasses::Vector3 worldScale = GetWorldScale();

	float scaleMod = (worldScale[0]);

	MathClasses::Vector3 finalMove = GetForward() * ((moveSpeed / scaleMod) * deltaTime);

	Translate(finalMove);
}