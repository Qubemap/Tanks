#pragma once

#include "SpriteObject.h"

class Projectile : public SpriteObject
{
public:

	float moveSpeed = 300.0f;

	bool ScheduleForDestruction = false;

	Projectile();

protected:

	void OnUpdate(float deltaTime) override;

	void OnCollision(GameObject* other) override;

};