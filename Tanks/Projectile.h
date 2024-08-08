#pragma once

#include "SpriteObject.h"

class Projectile : public SpriteObject
{
public:

	float moveSpeed = 300.0f;

protected:

	void OnUpdate(float deltaTime) override;

};