
#include "TankPlayer.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	SpriteObject::OnUpdate(deltaTime); //we do this if we have a hitbox

	this->delta = deltaTime;

	reloadTime--;

	GameObject* Turret = GetChild(0);

	MathClasses::Vector3 worldScale = GetWorldScale();

	scaleMod = (worldScale[0]); //compensates for worlds scale when moving

	// check for key input
	float yMove = 0.0f;

	float rot = 0.0f;

	float turretRot = 0.0f;

	//W-S for UP-Down movement
	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += moveSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= moveSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_A))
	{
		rot -= rotSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_D))
	{
		rot += rotSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_Q))
	{
		turretRot -= turretSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_E))
	{
		turretRot += turretSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_LEFT)) 
	{
		turretRot -= turretSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_RIGHT))
	{
		turretRot += turretSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_SPACE) && reloadTime <= 0)
	{
		Shoot();
		reloadTime = 100;
	}

	// displacement for this frame
	MathClasses::Vector3 finalMove = GetForward() * ((yMove / scaleMod) * deltaTime);

	Rotate(rot);

	Translate(finalMove);

	//Children[0]->Rotate(turretRot);

	Turret->Rotate(turretRot);

}

void TankPlayer::Shoot()
{

	GameObject* Turret = GetChild(0);

	Projectile* Bullet = new Projectile();

	Bullet->Sprite = bulletSprite;

	Bullet->SetLocalRotation(0);

	Bullet->SetLocalPosition(GetLocalPosition());

	Bullet->Rotate(GetLocalRotation() + Turret->GetLocalRotation());

	MathClasses::Vector3 offset = Bullet->GetForward() * 50;

	Bullet->Translate(offset);

	Bullet->SetParent(GetParent());

}

