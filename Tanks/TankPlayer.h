#pragma once

#include "SpriteObject.h"

class TankPlayer : public SpriteObject
{
public:

	float move_speed = 150.0f;

	float rot_speed = (1 * DEG2RAD);

	float turret_speed = (1 * DEG2RAD);

protected:
	void OnUpdate(float deltaTime) override;

	void Shoot();

};
