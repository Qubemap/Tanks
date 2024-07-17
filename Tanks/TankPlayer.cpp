#include "TankPlayer.h"

void TankPlayer::OnUpdate(float deltaTime)
{
	const float MOVESPEED = 150.0f;
	const float ROTSPEED = (1 * DEG2RAD);

	// check for key input
	float yMove = 0.0f;

	float rot = 0.0f;

	//W-S for UP-Down movement
	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= MOVESPEED;
	}

	if (IsKeyDown(KeyboardKey::KEY_Q))
	{
		rot += ROTSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_E))
	{
		rot -= ROTSPEED;
	}

	// displacement for this frame
	MathClasses::Vector3 finalMove = GetForward() * (yMove * deltaTime);

	Rotate(rot);

	Translate(finalMove);

	
}