#include "TankPlayer.h"
#include "Projectile.h"

void TankPlayer::OnUpdate(float deltaTime)
{

	GameObject* Turret = GetChild(0);

	MathClasses::Vector3 worldScale = GetWorldScale();

	float scaleMod = (worldScale[0]); //compensates for worlds scale when moving

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

	// displacement for this frame
	MathClasses::Vector3 finalMove = GetForward() * ((yMove / scaleMod) * deltaTime);

	Rotate(rot);

	Translate(finalMove);

	//Children[0]->Rotate(turretRot);

	Turret->Rotate(turretRot);

}

