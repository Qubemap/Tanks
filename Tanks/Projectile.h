#pragma once

#include "SpriteObject.h"

class Projectile : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
};