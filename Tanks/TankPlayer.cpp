#include "TankPlayer.h"
#include "Projectile.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	/*const float MOVESPEED = 150.0f;
	const float ROTSPEED = (1 * DEG2RAD);

	const float TURRETSPEED = (1 * DEG2RAD); */

	GameObject* Turret = GetChild(0);

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

	if (IsKeyDown(KeyboardKey::KEY_Q))
	{
		rot -= rotSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_E))
	{
		rot += rotSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_LEFT))
	{
		turretRot -= turretSpeed;
	}
	if (IsKeyDown(KeyboardKey::KEY_RIGHT))
	{
		turretRot += turretSpeed;
	}

	if (IsKeyDown(KeyboardKey::KEY_SPACE))
	{
		Shoot();
	}

	// displacement for this frame
	MathClasses::Vector3 finalMove = GetForward() * (yMove * deltaTime);

	Rotate(rot);

	Translate(finalMove);

	//Children[0]->Rotate(turretRot);

	Turret->Rotate(turretRot);

}

