#include "Projectile.h"

Projectile::Projectile()
{
	AddTag("bullet");
}

void Projectile::OnUpdate(float deltaTime)
{
	SpriteObject::OnUpdate(deltaTime);

	MathClasses::Vector3 worldScale = GetWorldScale();

	float scaleMod = (worldScale[0]);

	MathClasses::Vector3 finalMove = GetForward() * ((moveSpeed / scaleMod) * deltaTime);

	Translate(finalMove);

}

void Projectile::OnCollision(GameObject* other)
{
	if (other->HasTag("ImmovableObject"))
	{
		delete this; //this should remove it as a child of parent
	}
}