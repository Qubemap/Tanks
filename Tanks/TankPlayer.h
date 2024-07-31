#pragma once

#include "SpriteObject.h"

class TankPlayer : public SpriteObject
{
public:

	float moveSpeed = 150.0f;

	float rotSpeed = (1 * DEG2RAD);

	float turretSpeed = (1 * DEG2RAD);

protected:
	void OnUpdate(float deltaTime) override;

};
